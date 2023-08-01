//for ultra sonic sensor
#include <NewPing.h>

//for servo motors
#include <Servo.h>

//For communication Module 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "def.h"
#include "var.h"




//flags for encoder line following function
int flag  = 0;



//------------------turning angle--------------------------------//
#define turn_count_default 705    //for 90 degree
//-------------------------------------------------//
#define countRange 400


//for motors Encoder movement
int minSpeed = 80;
int midSpeed = 100;
int maxSpeed = 120;
float Kp = 0.2; //0.2
float Kd = 0.0001;

//-----------------------------------------//

//----------encoder turning--------//

int turn_minSpeed = 70;
int turn_midSpeed = 90;
int turn_maxSpeed = 110;
float t_Kp = 0;
float t_Kd = 0;



//----------For line following------------//
int lf_minSpeed = 45; //40
int lf_midSpeed = 70; //65
int lf_maxSpeed = 95; //90

//---constant for line following
float p , d , error ;
float i = 0 ;
float prev_error = 0 ;

float KP = 3 ;  //0.0175
float KD = 0.07 ;  //0.008
float KI = 0 ;  //0
//-----------------------------------//


void setup(){
  InitMotors();
  config();

}
  
//-------------For algorithim------------//
int section=1;
int subsection=0;

bool box_found = false;

//---------------------------------------//



void loop(){
  
if(section==1&& subsection==0){  //line following 

  if(white_line()==true){
    Brake(200);
    Forward(100,100);
    delay(300);
    right_90_new();
    Brake(200);
    allign();

    subsection=1;
   }
   else{
    lineFollowing();
  }

  }


else if(section==1 && subsection==1){

      unload();
      Brake(200);

      sending("start");
      delay(200);

      sending("start");
      delay(200);

      sending("start");
      delay(200);

      sending("start");
      delay(200);

      //delay the time for go to secondary robot
      led_blink(redLED); //2s delay
      led_blink(redLED);
      led_blink(greenLED);

      getload();
      subsection=2;
  


}

else if(section==1 && subsection==2){  
    if(left_junction()==true){
      Brake(200);
      Forward(100,100);
      delay(240);
      left_90_new();
      Brake(200);
      section=2;
      subsection=1;

    }

    else{
      lineFollowing();
    }

}
else if(section==2 && subsection==1){ 
  read_IR();
  if(IR_val[0]==0 && IR_val[7]==0){
    Forward(100,100);
    delay(100);
    Brake(100);
    subsection=2;
  }
  else{

    lineFollowing();
  }

}



else if (section==2 && subsection==2){ // colour receving 
  
  Recived_colour = receiving();
  if(Recived_colour == "red"){
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      section=3;
      subsection=3;
    
  }
  else if (Recived_colour=="green"){
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
           section=3;
      subsection=3;
    
  }

  else if (Recived_colour =="blue"){
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, HIGH);
      section=3;
      subsection=3;
    
  }

  else if(Recived_colour =="white"){
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, HIGH);


      section=3;
      subsection=3;
  }
}

else if (section==3 && subsection==3){ //after the check box go till the first junction  //
read_IR();
if(IR_val[8] == 0 ) {
  Brake(200); 
  goForwardspecificDistance(50, 50);
  Brake(200);
  right_90_new();
  allign();
  Brake(200);       
  section = 4;
  subsection = 3;          
  }
else{
  lineFollowing();
  
}  

}

else if(section==4 && subsection ==3){  //before turn to the first box

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED,LOW);
    digitalWrite(blueLED, LOW);

    goForwardspecificDistance(50,50);
    section=5;  //section 5 --> Box finding and grabing 
    subsection=1;

    

}

else if(section==5 && subsection==1){   // check the box is founded or not
  if (box_found == true){ //correct box was founded
    subsection=2;
    
  }

  else{
    read_junction_IR();
    
    if(IR_val[8]==0){  //turn to check the box colour

        Brake(200);

        goForwardspecificDistance(50,50);
        Brake(200);
        right_90_new();
        Brake(200);
        subsection=3;
    }
    else{
      lineFollowing();
    }
  }
}

else if (section==5 && subsection==2){ //box is founded
  read_IR();

  if(IR_val[9] == 0 ){ //detecting the white line 
    Brake(200);
    goForwardspecificDistance(50, 50);
    right_90_new(); //turn right to box hatching
    Brake(200);
    
    section = 5;
    subsection = 5;
  }

else{
  lineFollowing();
}
}

else if (section==5 && subsection ==3){ //go to the box
      int distance = sonar.ping_cm();
      if(distance<3 && distance != 0){
        Brake(200);
        goForwardspecificDistance(8,8);
        Brake(200);
        subsection=4;
      }
      else{
        lineFollowing();
      }
  
}

else if(section==5 && subsection==4){    //check the colour of the box
  if(check_colour(Recived_colour)==true){      //want to give reciving colour
    box_found=true;
    grab_arm();    // grab the box
    
  }
  else{
    box_found==false;
  }

  
  Brake(200);
  goBackwardspecificDistance(30, 30);
  Brake(200);
  left_180_new();
  Brake(200); 
  subsection=6;
  
}



else if(section==5 && subsection==6){  //turn right after box grabbing
  read_IR(); 

  if (IR_val[9] == 0) {
    Brake(200);
    goForwardspecificDistance(50, 50);
    right_90_new_allign();
   
    subsection = 1;
} 
 
else{
  lineFollowing();
}

}

else if(section==5 && subsection==5){  //turn left before box hatching
  
  read_IR(); 

  if (IR_val[9] == 0) {
    Brake(200);
    goForwardspecificDistance(50, 50);
    left_90_new(); // no need allign
    Brake(200);
   
    section = 6;
    subsection = 1;
} 
 
else{
  lineFollowing();
}

}
  
else if(section==6 && subsection==1){  //box hatching
 
  read_IR(); 

  if (IR_val[0] == 0 && IR_val[1] == 0 && IR_val[2] == 0 && IR_val[3] == 0 && IR_val[4] == 0 && IR_val[5] == 0 && IR_val[6] == 0 && IR_val[7] == 0) {
    Brake(200);
    goForwardspecificDistance(20, 20);
    Brake(200);
    release_arm();
    Brake(200);
    goBackwardspecificDistance(70, 70);
    Brake(200);
    left_180_new();
    Brake(200);
    
    
    section =6;
    subsection = 2;
} 
 
else{
  lineFollowing();
}
  

    
    }

else if(section==6 && subsection==2){ //after box hatch turn right from the junction
 
  read_IR(); 

  if (IR_val[8] == 0) {
    Brake(200);
    goForwardspecificDistance(50, 50);
    Brake(200);
    right_90_new_allign();
    Brake(200);
   
    section = 7;
    subsection = 1;
} 
 
else{
  lineFollowing();
}
  
}

else if(section==7 && subsection==1){  //after box hatch turn right from the 2nd junction before finish box
 
  read_IR(); 

  if (IR_val[8] == 0) {
    Brake(200);
    goForwardspecificDistance(50, 50);
    Brake(100);
    right_90_new_allign();
    Brake(200);
   
    section = 7;
    subsection = 2;
} 
 
else{
  lineFollowing();
}

}

else if(section==7 && subsection==2){  // stop at the finish box                   
   
  read_IR(); 

  if (IR_val[8] == 0) {
    Brake(200);
    goForwardspecificDistance(150, 150);
    Brake(200);
   
    section = 7;
    subsection = 3;
} 
 
else{
  lineFollowing();
}
}






}