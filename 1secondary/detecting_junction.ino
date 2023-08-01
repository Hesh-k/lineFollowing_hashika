
//for detecting Junctions -> left
bool left_junction(){

  int sensorValues[8];
  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }
 
  if(sensorValues[0]<threshold && sensorValues[1]<threshold && sensorValues[2]<threshold){
    return true;
  }
  else{
    return false;
  }
}

//for detecting junctions --> right
bool right_junction(){

    int sensorValues[8];
  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }


  if(sensorValues[7]<threshold && sensorValues[6]<threshold && sensorValues[5]<threshold){
    return true;
  }
  else{
    return false;
  }
}

//to detec white bar (left junction + right junction)
bool white_bar(){
     int sensorValues[8];
   for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }
 

  if(sensorValues[0]<threshold && sensorValues[1]<threshold && sensorValues[2]<threshold && sensorValues[3]<threshold && sensorValues[4]<threshold && sensorValues[5]<threshold && sensorValues[6]<threshold && sensorValues[7]<threshold){
    return true;
  }
  else{
    return false;
  }
}



bool black_bar(){
    int sensorValues[8];
   for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }

  if(sensorValues[0]>threshold && sensorValues[1]>threshold && sensorValues[2]>threshold && sensorValues[3]>threshold && sensorValues[4]>threshold && sensorValues[5]>threshold && sensorValues[6]>threshold && sensorValues[7]>threshold){
    return true;
  }
  else{
    return false;
  }
}


bool side_IR(){//black
    int sensorValues[8];
   for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }

  if(sensorValues[0]>threshold && sensorValues[7]>threshold){
    return true;
  }
  else{
    return false;
  }
}

bool mid_IR(){
   int sensorValues[8];
   for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(irPins[i]);
  }

//0 1 2 3 4 5 6 7
  if(sensorValues[3]>threshold && sensorValues[4]>threshold){
    return true;
  }
  else{
    return false;
  }

}