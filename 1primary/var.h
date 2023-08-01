#define VAR_H
#ifdef VAR_H

//--------------pins for LED bulbs-----------//

//RGB LED
int redLED = 42;
int blueLED = 43;
int greenLED = 41;

//pin for normal LED
int normalRed = 40;




//pins for encodes
const byte RM_EN_Pin = 3;  
const byte LM_EN_Pin = 2; 



RF24 radio(49, 48); // CE, CSN

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

//for ultrasonic distance variable
unsigned int distance;

// for colour 
 String Recived_colour = "red";



//for Encoder counting
volatile unsigned int RMEnCount = 0;
volatile unsigned int LMEnCount = 0;

//----------encoder movement ---------//

//PID constant  for motor movement
float previousError;
int enError = 0;
int rightMotorSpeed, leftMotorSpeed, motorSpeed;


//---for IR array
int IR_val[10] = {0,0,0,0,0,0,0,0,0,0} ;
int IR_weight[8] = {-800, -400, -200, -100, 100, 200, 400, 800};

//for NRF - addrsses
const byte addresses [][6] = {"00001", "00002"};  //Setting the two addresses. One for transmitting and one for receiving


// ############# create objects #####################//

// create servo object to control a servo
Servo arm;  
Servo unloard;

//create Ultra sonic Object
NewPing sonar(TRIGGER_PIN, ECHO_PIN,MAX_DISTANCE); // NewPing setup of pins and maximum distance




#endif