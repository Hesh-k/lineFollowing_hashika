//for colour sensor
int getRedPW() {
  // Set sensor to read Red only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
int getBluePW() {
  // Set sensor to read Blue only
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
int getGreenPW() {
  // Set sensor to read Green only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}


//for colour detection

bool check_colour(String colour_that_we_want){
  String box_colour;
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

  if ( redPW > greenPW && greenPW < bluePW) {

    box_colour = "green";
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
}

  else if (bluePW < greenPW && redPW > bluePW) {
    
    box_colour = "blue";
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);

}
 else if (redPW < greenPW && bluePW > redPW) {
  
    box_colour = "red";
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
  } 

  if (box_colour == colour_that_we_want){
    return true;
  }

  return false;
 
}
