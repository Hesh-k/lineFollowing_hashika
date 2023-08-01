//-----------for encoders ----------------//
//to get pulses
void attachInt() {
  attachInterrupt(digitalPinToInterrupt(RM_EN_Pin), RM_En_Count, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LM_EN_Pin), LM_En_Count, CHANGE);
}

//exit from getting pulses
void detachInt() {
  detachInterrupt(digitalPinToInterrupt(RM_EN_Pin));
  detachInterrupt(digitalPinToInterrupt(LM_EN_Pin));
}

void RM_En_Count() {
  ++RMEnCount;
}

void LM_En_Count() {
  ++LMEnCount;
}



//-------------------------------------------------------------//
//encoders enable
void  encoder_enable(){

      //Enable Encoders
      RMEnCount = 0;
      LMEnCount = 0;
      attachInt(); 
}