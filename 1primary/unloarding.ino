//-------Servo Motor Control-------------//

void unload(){
  
  int pos;
  for (pos = 180; pos >= 80; pos -=1) {  // loop from 180 degrees to 60 degrees in 5 steps
    unloard.write(pos);  // tell servo to go to position
    delay(20);  // wait for servo to reach position
    }
}

void getload(){
  int pos;
  for (pos = 70; pos <= 170; pos +=1) {  
    unloard.write(pos);  // tell servo to go to position
    delay(1);  // wait for servo to reach position
  }


}


