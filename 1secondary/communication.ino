// 3.) Communication.......................................


//for sending a word
void sending(const char* message) {
    delay(5);
  
    // Stop receiving and set the module as transmitter
    radio.stopListening();     

    // Send the message 40 times to reduce errors
    for(int i = 0; i < 40; i++) {
        radio.write(message, strlen(message) + 1);
        delay(20);
    }
}


//outputing the reciving word
String receiving(){
  
  delay(5);
  
  radio.startListening();   //This sets the module as transmitter     

  //reading the incomming massage  
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    //Serial.println(text);
    return String(text);
  }

  return "";
}

//----------------------------------------------------------//
