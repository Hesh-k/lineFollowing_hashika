void config(){

   //for communication
  radio.begin();     

  radio.openWritingPipe(addresses[1]);     //Setting the address to send data
  radio.openReadingPipe(1, addresses[0]);  //Setting the address to recive data
  
  radio.setPALevel(RF24_PA_MIN);           //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.   

  
  //----------------------Outputs -----------------//
  // pin difinition for LED
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Initialize motor driver pins
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1Dir, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2Dir, OUTPUT);

  //---------------------------------------------------//

  //----------------------------inputs--------------------//
  // Set Sensor output as input - for colour
  pinMode(sensorOut, INPUT);

  // Initialize IR sensor pins
  for (int i = 0; i < 8; i++) {
    pinMode(irPins[i], INPUT);
  }

  //------------------------------------------------------//

  // Set Pulse Width scaling to 20% for color sensor
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  


}