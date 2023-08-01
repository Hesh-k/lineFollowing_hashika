
//----------------movement by using Encoders---------------//
void goForwardspecificDistance(int firstCount, int secondCount) {
  RMEnCount = 0;
  LMEnCount = 0;

  attachInt();

  int totalCount = firstCount + secondCount;

  previousError = 0;

  while ((RMEnCount + LMEnCount) / 2 < totalCount) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * Kp  + (enError - previousError) * Kd;
    previousError = enError;

    if ((RMEnCount + LMEnCount) / 2 < firstCount) {

      rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
      leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
    } else {
      //minSpeed = 50;
      int decreaseSpeed = map((RMEnCount + LMEnCount) / 2, firstCount, totalCount, midSpeed, minSpeed);
      rightMotorSpeed = constrain((decreaseSpeed - motorSpeed), minSpeed, 2 * decreaseSpeed - minSpeed);
      leftMotorSpeed = constrain((decreaseSpeed + motorSpeed), minSpeed, 2 * decreaseSpeed - minSpeed);
    }
    Forward(rightMotorSpeed, leftMotorSpeed);
  }
  detachInt();
}

void goBackwardspecificDistance(int firstCount, int secondCount) {
  RMEnCount = 0;
  LMEnCount = 0;

  attachInt();

  int totalCount = firstCount + secondCount;

  previousError = 0;

  while ((RMEnCount + LMEnCount) / 2 < totalCount) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * Kp  + (enError - previousError) * Kd;
    previousError = enError;

    if ((RMEnCount + LMEnCount) / 2 < firstCount) {

      rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
      leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
    } else {
      //minSpeed = 50;
      int decreaseSpeed = map((RMEnCount + LMEnCount) / 2, firstCount, totalCount, midSpeed, minSpeed);
      rightMotorSpeed = constrain((decreaseSpeed - motorSpeed), minSpeed, 2 * decreaseSpeed - minSpeed);
      leftMotorSpeed = constrain((decreaseSpeed + motorSpeed), minSpeed, 2 * decreaseSpeed - minSpeed);
    }
    Backward(rightMotorSpeed, leftMotorSpeed);
  }
  detachInt();
}

void turnRight(int turn_count) {
  RMEnCount = 0;
  LMEnCount = 0;

  int counts = turn_count;

  attachInt();

  previousError = 0;

  while ((RMEnCount + LMEnCount) / 2 < counts ) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * t_Kp  + (enError - previousError) * t_Kd;
    previousError = enError;

    rightMotorSpeed = constrain((turn_midSpeed - motorSpeed), turn_minSpeed, turn_maxSpeed);
    leftMotorSpeed = constrain((turn_midSpeed + motorSpeed), turn_minSpeed, turn_maxSpeed);

    Right(rightMotorSpeed, leftMotorSpeed);                                                      //change

    if (digitalRead(A4) == 1 && ((RMEnCount + LMEnCount) / 2 > (counts - countRange)) ) {        //A5 , A6 , A7 digitalRead[A5] == 0 &&
      break;
    }
  }
  detachInt();

}

void turnLeft(int turn_count) {
  RMEnCount = 0;
  LMEnCount = 0;

  int counts = turn_count;

  attachInt();

  previousError = 0;
  while ((RMEnCount + LMEnCount) / 2 < counts ) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * Kp  + (enError - previousError) * Kd;
    previousError = enError;

    rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
    leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);

    Left(rightMotorSpeed, leftMotorSpeed);

    if (digitalRead(A3) == 1  &&  (RMEnCount + LMEnCount) / 2 > (counts - countRange) ) {          //A0 , A1 , A2
      break;
    }
  }
  detachInt();
}

void turnRight_from_one_wheel(int turn_count) {  //right wheel back
  RMEnCount = 0;
  LMEnCount = 0;

  int counts = turn_count;

  attachInt();

  previousError = 0;

  while ((RMEnCount + LMEnCount) / 2 < counts) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * t_Kp + (enError - previousError) * t_Kd;
    previousError = enError;

    //rightMotorSpeed = constrain((turn_midSpeed - motorSpeed), turn_minSpeed, turn_maxSpeed);
    rightMotorSpeed = 0;
    leftMotorSpeed = constrain((turn_midSpeed + motorSpeed), turn_minSpeed, turn_maxSpeed);;

    Right(rightMotorSpeed, leftMotorSpeed);  //change

    if (digitalRead(A4) == 0 && ((RMEnCount + LMEnCount) / 2 > (counts - countRange))) {  //A5 , A6 , A7 digitalRead[A5] == 0 &&
      break;
    }
  }
  detachInt();
}

void Right_wheel_forward(int turn_count) {  //right wheel forward
  RMEnCount = 0;
  LMEnCount = 0;

  int counts = turn_count;

  attachInt();

  previousError = 0;

  while ((RMEnCount + LMEnCount) / 2 < counts) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * t_Kp + (enError - previousError) * t_Kd;
    previousError = enError;

    //rightMotorSpeed = constrain((turn_midSpeed - motorSpeed), turn_minSpeed, turn_maxSpeed);
    rightMotorSpeed = 0;
    leftMotorSpeed = constrain((turn_midSpeed + motorSpeed), turn_minSpeed, turn_maxSpeed);;

    Left(rightMotorSpeed, leftMotorSpeed);  //change

    if (digitalRead(A4) == 0 && ((RMEnCount + LMEnCount) / 2 > (counts - countRange))) {  //A5 , A6 , A7 digitalRead[A5] == 0 &&
      break;
    }
  }
  detachInt();
}


void turnLeft_from_one_wheel(int turn_count) { //left_wheel_back
  RMEnCount = 0;
  LMEnCount = 0;

  int counts = turn_count;

  attachInt();

  previousError = 0;
  while ((RMEnCount + LMEnCount) / 2 < counts) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * Kp + (enError - previousError) * Kd;
    previousError = enError;

    rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
    leftMotorSpeed = 0;

    Left(rightMotorSpeed, leftMotorSpeed);

    if (digitalRead(A3) == 0 && (RMEnCount + LMEnCount) / 2 > (counts - countRange)) {  //A0 , A1 , A2
      break;
    }
  }
  detachInt();
}

void Left_wheel_forward(int turn_count) { //left_wheel_forward
  RMEnCount = 0;
  LMEnCount = 0;

  int counts = turn_count;

  attachInt();

  previousError = 0;
  while ((RMEnCount + LMEnCount) / 2 < counts) {
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * Kp + (enError - previousError) * Kd;
    previousError = enError;

    rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
    leftMotorSpeed = 0;

    Right(rightMotorSpeed, leftMotorSpeed);

    if (digitalRead(A3) == 0 && (RMEnCount + LMEnCount) / 2 > (counts - countRange)) {  //A0 , A1 , A2
      break;
    }
  }
  detachInt();
}


//.....Turning certain Angles...........//

void right_45(){
  turnRight(500);
  Brake(500);
}

void left_45(){
  turnLeft(500);
  Brake(500); 
}

void left_90(){
  turnLeft(600); //650 good
  Brake(1000);
  
}

void right_90(){
  turnRight(655); //650 good
  Brake(1000);
}

void  reverse_turn(){ // 180 degree

  // Left_wheel_forward(330);
  // Brake(1000);

  // turnRight_from_one_wheel(330);
  // Brake(1000);

  turnRight(1050);
  Brake(200);

  
  
}

//--------------------------------------//


//function for go line following with encoder count
void encoder_line_following(int distance,int next_subsection){
  if(flag==0){
    encoder_enable();
    flag++;
  }
  else{
    
    if(RMEnCount>distance){
      Brake(1000);
      detachInt();
      Brake(100);
      flag=0;
      subsection=next_subsection;
    }
    else{
      lineFollowing();
    }
  }  
}



