//-----------PID line Following---------------//

void lineFollowingWithDistance(int firstCount, int secondCount) {

  read_IR();
  error = 0 ;

  for (int i=0; i<=7; i++) {
    error += IR_val[i]*IR_weight[i] ;
    }

  p = error ;
  i = i + error ;
  d = error - prev_error ;
  prev_error = error ;

  float PID_val = (p*KP + i*KI + d*KD);
  int PID_val_int = round(PID_val);

  RMEnCount = 0;
  LMEnCount = 0;
  attachInt();
  
  int totalCount = firstCount + secondCount;

  previousError = 0;

  while ((RMEnCount + LMEnCount) / 2 < totalCount) {

    // calculate line following PID
    rightMotorSpeed = constrain((lf_midSpeed - PID_val_int), lf_minSpeed, lf_maxSpeed);
    leftMotorSpeed = constrain((lf_midSpeed + PID_val_int), lf_minSpeed, lf_maxSpeed);
    
    // calculate encoder PID
    enError = RMEnCount - LMEnCount;
    motorSpeed = enError * Kp  + (enError - previousError) * Kd;
    previousError = enError;

    // adjust speed based on distance traveled
    if ((RMEnCount + LMEnCount) / 2 < firstCount) {
      rightMotorSpeed = constrain((rightMotorSpeed - motorSpeed), lf_minSpeed, lf_maxSpeed);
      leftMotorSpeed = constrain((leftMotorSpeed + motorSpeed), lf_minSpeed, lf_maxSpeed);
    } else {
      int decreaseSpeed = map((RMEnCount + LMEnCount) / 2, firstCount, totalCount, lf_midSpeed, lf_minSpeed);
      rightMotorSpeed = constrain((rightMotorSpeed - motorSpeed), lf_minSpeed, 2 * decreaseSpeed - lf_minSpeed);
      leftMotorSpeed = constrain((leftMotorSpeed + motorSpeed), lf_minSpeed, 2 * decreaseSpeed - lf_minSpeed);
    }

    Forward(leftMotorSpeed, rightMotorSpeed);
  }

  detachInt();
}

void lineFollowing() {

  read_IR();
  error = 0 ;

  for (int i=0; i<=7; i++) {
    error += IR_val[i]*IR_weight[i] ;
    }

  p = error ;
  i = i + error ;
  d = error - prev_error ;
  prev_error = error ;

  float PID_val = (p*KP + i*KI + d*KD);
  int PID_val_int = round(PID_val);
 


  rightMotorSpeed = constrain((lf_midSpeed - PID_val_int), lf_minSpeed, lf_maxSpeed);
  leftMotorSpeed = constrain((lf_midSpeed + PID_val_int), lf_minSpeed, lf_maxSpeed);


  Forward(leftMotorSpeed,rightMotorSpeed);
  
}

void high_lineFollowing() {
  KP = 2 ;  //0.0175
  KD = 0.008 ;  //0.008
  KI = 0 ;  //0
  read_IR();

  if (IR_val[0]==1 && IR_val[1]==1 && IR_val[2]==1 && IR_val[3]==1 && IR_val[4]==1 && IR_val[5]==1 && IR_val[6]==1 && IR_val[7]==1){
    Forward(40,40);
  
  }
  else{   
    error = 0 ;

    for (int i=0; i<=7; i++) {


       lf_minSpeed = 30; //40
       lf_midSpeed = 60; //65
       lf_maxSpeed = 100; //90
      error += IR_val[i]*IR_weight[i] ;
      }

    p = error ;
    i = i + error ;
    d = error - prev_error ;
    prev_error = error ;

    float PID_val = (p*KP + i*KI + d*KD);
    int PID_val_int = round(PID_val);


    rightMotorSpeed = constrain((lf_midSpeed - PID_val_int), lf_minSpeed, lf_maxSpeed);
    leftMotorSpeed = constrain((lf_midSpeed + PID_val_int), lf_minSpeed, lf_maxSpeed);
    Forward(leftMotorSpeed,rightMotorSpeed);
  }
  
}



void low_lineFollowing() {
  KP = 0.0175 ;  //0.0175
  KD = 0.01 ;  //0.008
  KI = 0 ;  //0
  read_IR();

     
    error = 0 ;

    for (int i=0; i<=7; i++) {


       lf_minSpeed = 35; //40
       lf_midSpeed = 60; //65
       lf_maxSpeed = 85; //90
      error += IR_val[i]*IR_weight[i] ;
      }

    p = error ;
    i = i + error ;
    d = error - prev_error ;
    prev_error = error ;

    float PID_val = (p*KP + i*KI + d*KD);
    int PID_val_int = round(PID_val);


    rightMotorSpeed = constrain((lf_midSpeed - PID_val_int), lf_minSpeed, lf_maxSpeed);
    leftMotorSpeed = constrain((lf_midSpeed + PID_val_int), lf_minSpeed, lf_maxSpeed);
    Forward(leftMotorSpeed,rightMotorSpeed);
  
  
}


