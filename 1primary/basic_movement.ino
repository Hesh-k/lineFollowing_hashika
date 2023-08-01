
//----------------general movements--------------------------//
void Forward(int rms, int lms) {
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  analogWrite(RIGHT_MOTOR_PWM, rms);
  analogWrite(LEFT_MOTOR_PWM, lms);
}

void Backward(int rms, int lms) {
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);
  analogWrite(RIGHT_MOTOR_PWM, rms);
  analogWrite(LEFT_MOTOR_PWM, lms);
}

void Left(int rms, int lms) {
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  analogWrite(RIGHT_MOTOR_PWM, rms);
  analogWrite(LEFT_MOTOR_PWM, lms);
}

void Right(int rms, int lms) {
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);
  analogWrite(RIGHT_MOTOR_PWM, rms);
  analogWrite(LEFT_MOTOR_PWM, lms);
}

void PasBrake(int dly) {            //passive Brake
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, HIGH);
  analogWrite(RIGHT_MOTOR_PWM, 0);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, HIGH);
  analogWrite(LEFT_MOTOR_PWM, 0);
  delay(dly);
}

void Brake(int dly) {                    //active brake
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
  analogWrite(RIGHT_MOTOR_PWM, 0);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
  analogWrite(LEFT_MOTOR_PWM, 0);
  delay(dly);
}



void right_90_new(){
  Right(100,100);
  delay(300);
  do{
    Right(100,100);

  }

  while(mid_IR()==true);
  Brake(200);

}

void right_90_new_allign(){
  Right(100,100);
  delay(300);
  do{
    Right(100,100);

  }

  while(mid_IR()==true);
  allign();
  Brake(200);

}


void left_90_new(){
  Left(100,100);
  delay(300);
  do{
    Left(100,100);

  }

  while(mid_IR()==true);
  Brake(200);

}

void left_90_new_allign(){
  Left(100,100);
  delay(300);
  do{
    Left(100,100);

  }

  while(mid_IR()==true);
  allign();
  Brake(200);

}



void left_180_new(){
  Left(100,100);
  delay(600);
  do{
    Left(100,100);

  }

  while(mid_IRx()==true);
  
  
  PasBrake(200);

}



void left_90_xx(){
  Left(100,100);
  delay(60);
  do{
    Left(100,100);

  }

  while(mid_IR()==true);
  PasBrake(200);

}



void allign(){

  read_IR();
  do{
    read_IR();
    lineFollowing();

  }

  while(IR_val[0] !=1 || IR_val[7] !=1 || IR_val[3] !=0 || IR_val[4] !=0 && IR_val[1] !=1 || IR_val[6] !=1 );


  Brake(100);
}