
void line_following_pid_forward() { //speed 150 (less than normal)

  // Read sensor values
  int sensorValues[8];
  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }

  // Calculate error value
  float error = 0.0;
  for (int i = 0; i < 8; i++) {
    if (sensorValues[i] > threshold) {
      error += (i - 3.275); // 3.35
    }
  }

  // PID control
  float output = 0.0;
  output += kp * error;               // proportional term
  integral += error;                  // integral term
  output += ki * integral;            // integral term
  output += kd * (error - lastError); // derivative term
  lastError = error;

  // Adjust motor speeds based on PID output
  int leftMotorSpeed = motorSpeed - output;
  int rightMotorSpeed = motorSpeed + output;

  // Make sure motor speeds are within bounds
  if (leftMotorSpeed < 0) {
    leftMotorSpeed = 0;
  }
  if (leftMotorSpeed > 255) {
    leftMotorSpeed = 255;
  }
  if (rightMotorSpeed < 0) {
    rightMotorSpeed = 0;
  }
  if (rightMotorSpeed > 255) {
    rightMotorSpeed = 255;
  }

  // Set motor directions and speeds
  digitalWrite(motor1Dir, HIGH);           // set direction of left motor
  analogWrite(motor1PWM, leftMotorSpeed);  // set speed of left motor
  digitalWrite(motor2Dir, HIGH);           // set direction of right motor
  analogWrite(motor2PWM, rightMotorSpeed); // set speed of right motor
}



void  dotted_line_following() { //speed 150 (less than normal)

  const float kpd = 10;
  const float kdd = 0.7;
  const float kid  = 0;
  

  // Read sensor values
  int sensorValues[8];
  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }

  
  //for black area 
  if (sensorValues[0]>threshold && sensorValues[1] >threshold && sensorValues[2]>threshold && sensorValues[3]>threshold && sensorValues[4]>threshold && sensorValues[5]>threshold && sensorValues[6]>threshold && sensorValues[7] > threshold){

   digitalWrite(motor1Dir, HIGH);           // set direction of left motor
  analogWrite(motor1PWM, 207);  // set speed of left motor
  digitalWrite(motor2Dir, HIGH);           // set direction of right motor
  analogWrite(motor2PWM, 200); // set speed of right motor

  
  }

  //for white lines
  else{
  

  // Calculate error value
  float error = 0.0;
  for (int i = 0; i < 8; i++) {
    if (sensorValues[i] > threshold) {
      error += (i - 3.275); // 3.35
    }
  }

  // PID control
  float output = 0.0;
  output += kpd * error;               // proportional term
  integral += error;                  // integral term
  output += kid * integral;            // integral term
  output += kdd * (error - lastError); // derivative term
  lastError = error;

  // Adjust motor speeds based on PID output
  int motorSpeed = 150; // base speed
  int leftMotorSpeed = motorSpeed - output;
  int rightMotorSpeed = motorSpeed + output;

  // Make sure motor speeds are within bounds
  if (leftMotorSpeed < 0) {
    leftMotorSpeed = 0;
  }
  if (leftMotorSpeed > 255) {
    leftMotorSpeed = 255;
  }
  if (rightMotorSpeed < 0) {
    rightMotorSpeed = 0;
  }
  if (rightMotorSpeed > 255) {
    rightMotorSpeed = 255;
  }

  // Set motor directions and speeds
  digitalWrite(motor1Dir, HIGH);           // set direction of left motor
  analogWrite(motor1PWM, leftMotorSpeed);  // set speed of left motor
  digitalWrite(motor2Dir, HIGH);           // set direction of right motor
  analogWrite(motor2PWM, rightMotorSpeed); // set speed of right motor
}

}

void  high_dotted_line_following() { //speed 150 (less than normal)

  const float kpd = 20;
  const float kdd = 6;
  const float kid  = 0.1;
  

  // Read sensor values
  int sensorValues[8];
  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }

  
  //for black area 
  if (sensorValues[0]>threshold && sensorValues[1] >threshold && sensorValues[2]>threshold && sensorValues[3]>threshold && sensorValues[4]>threshold && sensorValues[5]>threshold && sensorValues[6]>threshold && sensorValues[7] > threshold){

   digitalWrite(motor1Dir, HIGH);           // set direction of left motor
  analogWrite(motor1PWM, 207);  // set speed of left motor //207
  digitalWrite(motor2Dir, HIGH);           // set direction of right motor
  analogWrite(motor2PWM, 200); // set speed of right motor  //200

    
    
  }

  //for white lines
  else{
  

  // Calculate error value
  float error = 0.0;
  for (int i = 0; i < 8; i++) {
    if (sensorValues[i] > threshold) {
      error += (i - 3.275); // 3.35
    }
  }

  // PID control
  float output = 0.0;
  output += kpd * error;               // proportional term
  integral += error;                  // integral term
  output += kid * integral;            // integral term
  output += kdd * (error - lastError); // derivative term
  lastError = error;

  // Adjust motor speeds based on PID output
  int leftMotorSpeed = motorSpeed - output;
  int rightMotorSpeed = motorSpeed + output;

  // Make sure motor speeds are within bounds
  if (leftMotorSpeed < 0) {
    leftMotorSpeed = 0;
  }
  if (leftMotorSpeed > 255) {
    leftMotorSpeed = 255;
  }
  if (rightMotorSpeed < 0) {
    rightMotorSpeed = 0;
  }
  if (rightMotorSpeed > 255) {
    rightMotorSpeed = 255;
  }

  // Set motor directions and speeds
  digitalWrite(motor1Dir, HIGH);           // set direction of left motor
  analogWrite(motor1PWM, leftMotorSpeed);  // set speed of left motor
  digitalWrite(motor2Dir, HIGH);           // set direction of right motor
  analogWrite(motor2PWM, rightMotorSpeed); // set speed of right motor
}

}
