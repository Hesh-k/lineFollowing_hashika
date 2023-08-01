#ifndef VAR_H 
#define VAR_H




// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;


// Variables for PID control
float lastError = 0.0;
float integral = 0.0;


//Two addresses to communication
const byte addresses [][6] = {"00001", "00002"}; //One for transmitting and one for receiving

// 00001 - for reading address
// 00002 - for writing address

//for algorithm

bool dotted =false;




#endif