
//taking IR values............//

void read_junction_IR(){
    IR_val[8] = analogRead(A8) ;     //right junction IR
    IR_val[9] = analogRead(A9) ;     //left  junction IR

    if(IR_val[8]>300){
      IR_val[8] = 1;
    }else{
      IR_val[8] = 0;
      }  

    if(IR_val[9]>300){
      IR_val[9] = 1;
    }else{
      IR_val[9] = 0;
      }       

}

void read_IR(){
   
      IR_val[0] = analogRead(A0) ;        //right panel
      IR_val[1] = analogRead(A1) ;
      IR_val[2] = analogRead(A2) ;
      IR_val[3] = analogRead(A3) ;
      IR_val[4] = analogRead(A4) ;
      IR_val[5] = analogRead(A5) ;
      IR_val[6] = analogRead(A6) ;
      IR_val[7] = analogRead(A7) ;
      IR_val[8] = analogRead(A8) ;     //right junction IR
      IR_val[9] = analogRead(A9) ;     //left  junction IR

      if(IR_val[0]>250){
        IR_val[0] = 1;
      }else{
        IR_val[0] = 0;
      }

      if(IR_val[1]>250){
        IR_val[1] = 1;
      }else{
        IR_val[1] = 0;
      }

      if(IR_val[2]>250){
        IR_val[2] = 1;
      }else{
        IR_val[2] = 0;
      }

      if(IR_val[3]>250){
        IR_val[3] = 1;
      }else{
        IR_val[3] = 0;
      }

      if(IR_val[4]>250){
        IR_val[4] = 1;
      }else{
        IR_val[4] = 0;
      }

      if(IR_val[5]>250){
        IR_val[5] = 1;
      }else{
        IR_val[5] = 0;
      }

      if(IR_val[6]>250){
        IR_val[6] = 1;
      }else{
        IR_val[6] = 0;
      }
      
      if(IR_val[7]>250){
        IR_val[7] = 1;
      }else{
        IR_val[7] = 0;
      }
      if(IR_val[8]>250){
        IR_val[8] = 1;
      }else{
        IR_val[8] = 0;
      }  

      if(IR_val[9]>250){
        IR_val[9] = 1;
      }else{
        IR_val[9] = 0;
      }       
} 


bool white_line(){
  read_IR();
  if (IR_val[0]==1 && IR_val[1]==1 && IR_val[2]==1 && IR_val[3]==1 && IR_val[4]==1 && IR_val[5]==1 && IR_val[6]==1 && IR_val[7]==1){
    return true;
  }
  else{
    return false;
  }
}

bool right_junction(){
  read_IR();
  if(IR_val[0]==1 && IR_val[1]==1 && IR_val[2]==1){
    return true;
  }
  else{
    return false;
  }
}


bool left_junction(){
  read_IR();
  if(IR_val[7]==1 && IR_val[6]==1 && IR_val[5]==1){
    return true;
  }
  else{
    return false;
  }
}

bool mid_IR(){
  read_IR();
  if(IR_val[5]==1 && IR_val[4]==1){
    return true;
  }
  else{
    return false;
  }
}

bool mid_IRx(){
  read_IR();
  if(IR_val[5]==1 && IR_val[6]==1){
    return true;
  }
  else{
    return false;
  }
}

