#define TUNING_H
#ifdef TUNING_H



//------------------turning angle--------------------------------//
#define turn_count_default 705    //for 90 degree
//-------------------------------------------------//
#define countRange 400


//for motors Encoder movement
int minSpeed = 80;
int midSpeed = 100;
int maxSpeed = 120;
float Kp = 0.2; //0.2
float Kd = 0.0001;

//-----------------------------------------//

//----------encoder turning--------//

int turn_minSpeed = 70;
int turn_midSpeed = 90;
int turn_maxSpeed = 110;
float t_Kp = 0;
float t_Kd = 0;


//----------For line following------------//
int lf_minSpeed = 45; //40
int lf_midSpeed = 70; //65
int lf_maxSpeed = 95; //90

//---constant for line following
float p , d , error ;
float i = 0 ;
float prev_error = 0 ;

float KP = 0.1 ;  //0.0175
float KD = 0.008 ;  //0.008
float KI = 0 ;  //0
//-----------------------------------//



#endif