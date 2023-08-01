//for ultra sonic sensor
#include <NewPing.h>

//for NRF communication
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//custon headers
#include "def.h"
#include "pins.h"
#include "var.h"


// ----------------For Tuning -------------------//

// Threshold value for detecting black vs white (IR)
const int threshold = 700;  //500 // 700 for low lights

// base speed of the motor (speed)
int motorSpeed = 50; // include them inside functions

// PID constants (line following)
const float kp = 15;   // proportional gain
const float ki = 0.1; // integral gain
const float kd = 4;   // derivative gain

//for rotation delay (rotate delay)
int ninty = 550; //90
int d180 =  1200;   //180

//----------------------------------------------------//

void setup() {
  // for serial monitor
  Serial.begin(9600);

  config();
 
}

//for box detection colour 
String colour ;
//--------------------//

//--------for algorithm-----------//
int section =1;
int subsection =1;




void loop() {

  if(section==1 && subsection==1){ // transmission - ok

    digitalWrite(normalRed, HIGH);
    String start_massage = receiving();
    delay(100);
    digitalWrite(normalRed, LOW);
    delay(100);
      if (start_massage=="start"){
        
        digitalWrite(normalBlue, HIGH);
        delay(200);
        digitalWrite(normalBlue, LOW);

        subsection=2; // to white line

      }
}

else if(section==1 && subsection==2){

  if(white_bar()==true){
    forward();
    delay(150);

    section=2;  // --> to maze
    subsection=1;
  }

  else{
    line_following_pid_forward();
  }

}

else if(section==2 && subsection==1){ // maze sloving - right priority

  if(right_junction()==true || white_bar()==true){

    forward(); 
    delay(200);
    if(white_bar()==true){
      stop();
      delay(100);
      section=3; // go to next checkpoint
    }
    else{
      stop();
      delay(200);
     rotate_90_right();       

                
    }
  }

  else if(left_junction()==true && right_junction()==false){
    
    forward();
    delay(200);

    if(white_bar()==true){
        section==3; //go to checkpoint 

    }

    else if (black_bar()==false) {
      line_following_pid_forward();
    }
    else{
      stop();
      delay(200);
      rotate_90_left();
    }
  }

  else if(black_bar()==true){

    forward();
    delay(200);

    if(black_bar()==true){
      stop();
      delay(200);
      rotate_180();
    }   

  }

  else{
    line_following_pid_forward();
  }



}


else if (section ==3 && subsection==1){ //dotted line , colour detection  and colour sending 

  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the
             // shortest delay between pings.
  int distance = sonar.ping_cm(); // Send ping, get distance in cm and print
                                  // result (0 = outside set distance range)



  //_________after detecting the box_______________
  if (distance == 2 && distance !=0) {
    stop();
    digitalWrite(normalRed, HIGH);
    // Read Red Pulse Width
    redPW = getRedPW();
    // Delay to stabilize sensor
    delay(200);

    // Read Green Pulse Width
    greenPW = getGreenPW();
    // Delay to stabilize sensor
    delay(200);

    // Read Blue Pulse Width
    bluePW = getBluePW();
    // Delay to stabilize sensor
    delay(200);
    digitalWrite(normalRed, LOW);


    int minimum = min(min(redPW, bluePW), greenPW);
    int average = (redPW + bluePW + greenPW) / 3;
    int difference = abs(minimum - average);

    if (redPW < 50 && bluePW < 50 && greenPW < 50) {

      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, HIGH);

      //white communicate 
      digitalWrite(normalRed, HIGH);
      sending("white");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);

      
      digitalWrite(normalRed, HIGH);
      sending("white");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);

      //---------------------

    } else if ( redPW > greenPW && greenPW < bluePW) {

      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);

      //red communicate 
      digitalWrite(normalRed, HIGH);
      sending("green");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);

      
      digitalWrite(normalRed, HIGH);
      sending("green");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);
      //---------------

    } else if (bluePW < greenPW && redPW > bluePW) {

      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, HIGH);
    
      //blue communicate
      digitalWrite(normalRed, HIGH);
      sending("blue");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);

      
      digitalWrite(normalRed, HIGH);
      sending("blue");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);
      //----------
    
    } else if (redPW < greenPW && bluePW > redPW) {

      Serial.print("red  ");
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);

        //red communicate
      digitalWrite(normalRed, HIGH);
      sending("red");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);

      
      digitalWrite(normalRed, HIGH);
      sending("red");
      delay(500);
      digitalWrite(normalRed, LOW);
      delay(500);
      //-------
    }

    delay(500);
    digitalWrite(normalBlue,HIGH);
    delay(1000);
    digitalWrite(normalBlue,LOW);
    subsection =2;
  
  } 
  else {
    line_following_pid_forward();
  }

}

else if (section==3 && subsection==2){ // for rotation to come back
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);

    
  
    //finish sending
    delay(500);
    
    rotate_180_from_left();
    subsection =3;
    
  
}

else if(section==3 && subsection==3){  // going to line while finding junction


    if(white_bar()==true){

      forward(); 
      delay(200);

      rotate_90_right();
      section=4;
      subsection=1;
    }
    else{

      line_following_pid_forward();
    }
    

      
}

else if (section==4 && subsection==1 ){
  if(white_bar()==true){

    forward();  // go forward until robot in middle of box
    delay(400);

    stop();
    section=5; // end 
  }  
  else{
    high_dotted_line_following();
  }
}


  
}