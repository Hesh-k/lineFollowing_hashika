//-------for pin setups----//
void InitMotors() {
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  pinMode(RM_EN_Pin, INPUT_PULLUP);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
  pinMode(LM_EN_Pin, INPUT_PULLUP);

  digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
  digitalWrite(LEFT_MOTOR_ENABLE, HIGH);

}

void config(){
  Serial.begin(9600);

  //servo pins
  arm.attach(10);  
  unloard.attach(11);


  //initial positions of arm and unloarding 
  unloard.write(170); // for unloarding door
  arm.write(0); //for arm


  //for radio communicaiton
  radio.begin();                           //Starting the radio communication
  radio.openWritingPipe(addresses[0]);     //Setting the address at which we will send the data
  radio.openReadingPipe(0, addresses[1]);  //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);           //You can set it as minimum or maximum depending on the distance between the transmitter and receiver. 

  //---------------for Colour sensor ---------------------//  
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);

  
}