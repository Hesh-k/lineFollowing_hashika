//  1.) movements.....................................

void forward() {
  digitalWrite(motor1Dir, HIGH);      // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, HIGH);      // set direction of right motor
  analogWrite(motor2PWM, motorSpeed); // set speed of right motor
}

void stop() {
  digitalWrite(motor1Dir, LOW); // set direction of left motor
  analogWrite(motor1PWM, 0);    // set speed of left motor
  digitalWrite(motor2Dir, LOW); // set direction of right motor
  analogWrite(motor2PWM, 0);    // set speed of right motor
}

void rotate_right(){
  digitalWrite(motor1Dir, LOW); // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, HIGH); // set direction of right motor
  analogWrite(motor2PWM, motorSpeed); // set speed of right motor
}

void rotate_left(){
  digitalWrite(motor1Dir, HIGH); // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, LOW); // set direction of right motor
  analogWrite(motor2PWM, motorSpeed); // set speed of right motor
}

void backward_slow(){
  digitalWrite(motor1Dir, LOW); // set direction of left motor
  analogWrite(motor1PWM, 70); // set speed of left motor
  digitalWrite(motor2Dir, LOW); // set direction of right motor
  analogWrite(motor2PWM, 70); // set speed of right motor
}

void rotate_90_left(){

  rotate_left();
  delay(450); 
  do{
    rotate_left();

  }
  while(mid_IR()==true);

  stop();
  delay(200);

}

void rotate_90_right(){
  rotate_right();
  delay(450); //
  do{
    rotate_right();
  }
  while(mid_IR()==true);
  stop();
  delay(200);
}

void rotate_180(){
  stop();
 
  digitalWrite(motor1Dir, LOW); // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, HIGH); // set direction of right motor
  analogWrite(motor2PWM, motorSpeed * 2.5); // set speed of right motor


  delay(600);

  do{
     
  digitalWrite(motor1Dir, LOW); // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, HIGH); // set direction of right motor
  analogWrite(motor2PWM, motorSpeed *2.5); // set speed of right motor


  }
  while(mid_IR()==true);
  stop();
  delay(200);

  
}

void rotate_180_from_left(){
    stop();
 
  digitalWrite(motor1Dir, HIGH); // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, LOW); // set direction of right motor
  analogWrite(motor2PWM, motorSpeed * 2.5); // set speed of right motor


  delay(600);

  do{
     
  digitalWrite(motor1Dir, HIGH); // set direction of left motor
  analogWrite(motor1PWM, motorSpeed); // set speed of left motor
  digitalWrite(motor2Dir, LOW); // set direction of right motor
  analogWrite(motor2PWM, motorSpeed *2.5); // set speed of right motor


  }
  while(mid_IR()==true);
  stop();
  delay(200);



}


