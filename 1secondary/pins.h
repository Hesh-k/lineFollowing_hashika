#ifndef PINS_H 
#define PINS_H



//---------------- pin difinition  ---------------------//



// pins for RGB sensor
int redLED = 19;
int blueLED = 17;
int greenLED = 18;

//pin for normal LED
int normalRed = 31;
int normalBlue = 16;



// Pin definitions for motor driver
// right motor-- motor 1
const int motor1PWM = 2;
const int motor1Dir = 3;

// left motor -- motor 2
const int motor2PWM = 5;
const int motor2Dir = 4;

// Pin definitions for IR sensors
const int irPins[8] = {A0, A1, A2, A3, A4, A5, A6, A7};

//pin difinition for NRF communication module
RF24 radio(49, 48); 



#endif