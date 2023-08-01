
void grab_arm(){
  arm.write(0);   // open position of arm
  delay(1000);         // waits for a second
  arm.write(50);   // close position of arm
  delay(2000); 
  
}

void release_arm(){
  arm.write(50);   // close position
  delay(1000);         // waits for a second
  arm.write(0);   // open position
  delay(2000); 
  
}
