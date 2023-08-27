#include <Wire.h>

#define PCF8574T_ADDRESS 0x20

// Motor pins
const int motor1EnablePin = 10;
const int motor2EnablePin = 11;
const int motor1DirectionPin = 12;
const int motor2DirectionPin = 13;

// PID constants
double kp = 0.1;
double ki = 0.01;
double kd = 0.5;

int motorSpeedBase = 150;
int maxMotorSpeed = 255;

int lastError = 0;
int integral = 0;

// Line detection logic
const int numSensors = 8;
const int threshold = 500;

const int irPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  Wire.begin();
  Wire.beginTransmission(PCF8574T_ADDRESS);
  Wire.write(0xFF); // Set all pins as INPUT
  Wire.endTransmission();
  
  pinMode(motor1EnablePin, OUTPUT);
  pinMode(motor2EnablePin, OUTPUT);
  pinMode(motor1DirectionPin, OUTPUT);
  pinMode(motor2DirectionPin, OUTPUT);
  
  for (int i = 0; i < numSensors; i++) {
    pinMode(irPins[i], INPUT);
  }
}

void readIRValues(bool sensorValues[]) {
  Wire.requestFrom(PCF8574T_ADDRESS, 1);
  if (Wire.available()) {
    byte sensorData = Wire.read();
    
    // Read individual sensor values
    for (int i = 0; i < numSensors; i++) {
      sensorValues[i] = !bitRead(sensorData, i); // Invert because LOW means line detected
    }
  }
}

bool black_bar(bool sensorValues[]) {
  for (int i = 0; i < numSensors; i++) {
    if (!sensorValues[i]) {
      return false;  // If any sensor doesn't detect the line, it's not a black bar
    }
  }
  return true;  // If all sensors detect the line, it's a black bar
}

bool left_junction(bool sensorValues[]) {
  return sensorValues[0] && sensorValues[1] && sensorValues[2];
}

bool right_junction(bool sensorValues[]) {
  return sensorValues[7] && sensorValues[6] && sensorValues[5];
}

// ... other turning logic functions ...

void loop() {
  bool sensorValues[numSensors];
  readIRValues(sensorValues);

  bool lineDetected = !black_bar(sensorValues);
  
  if (lineDetected) {
    // ... PID control and motor actuation ...

  } else if (left_junction(sensorValues)) {
    // Perform left turn logic
    // ...

  } else if (right_junction(sensorValues)) {
    // Perform right turn logic
    // ...

  } else {
    // No line and no junction detected, adjust robot behavior accordingly
    // ...

  }
  
  delay(10);  // Adjust delay as needed
}
