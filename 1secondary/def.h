#ifndef DEF_H 
#define DEF_H

// pins for untrasonic sensor
#define TRIGGER_PIN 23
#define ECHO_PIN 22
#define MAX_DISTANCE 200 // Maximum distance we want to measure (in centimeters).

// pins for colour sensor
#define S0 9
#define S1 8
#define S2 7
#define S3 6
#define sensorOut 10



//---------------------------create objects-----------------------------//

NewPing sonar(TRIGGER_PIN, ECHO_PIN,MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//------------------------------------------------------------------------------//


#endif