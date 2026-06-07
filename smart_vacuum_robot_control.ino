Arduino robot control code
/*------------------ -------- ---- Tonmoy--------------------------- */
//-------------- Control --------------/
#define M A5       //  Manual or auto
#define F A0      // FORWORD CONTROL /// YELLOW
#define R A1      // RIGHT CONTROL   /// BLUE
#define L A2      // LEFT CONTROL    ///  RED
#define B A3      // BACK CONTROL    ///  GREEN
#define S A4      // sweeper start 

/*-------definning Inputs------FOR IR--------*/
#define LS 2      // left sensor
#define RS 3      // right sensor
#define drm 4      // drum sensor

/*-------definning Output ------FOR PWM --------*/
#define P 9       // sweeper speed

/*-------definning Inputs------FOR ULTRA FOR LEFT------*/
#define TRIG_L  10   // RED
#define ECO_L   11   // WHITE
int frontdist_L;    
long duration_L;
int setdist=100;

/*-------definning Inputs------FOR ULTRA FOR RIGHT------*/
#define TRIG_R  12    // RED
#define ECO_R   13    // GRAY
int frontdist_R;
long duration_R;

/*-------definning Outputs------*/

#define PWM 5       // start motor
#define LM 6       //  right motor
#define RM 7       // LEFT motor
#define VC 8       // vacumm cleaner

void setup()
{
  pinMode(M, INPUT);
  pinMode(F, INPUT);
  pinMode(R, INPUT);
  pinMode(L, INPUT);
  pinMode(B, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(drm, INPUT);
  pinMode(LM, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(VC, OUTPUT);
  pinMode(P, OUTPUT);
  pinMode(S, OUTPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECO_L, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECO_R, INPUT);
  Serial.begin(9600);
  delay(0);
}

void loop()
{
  if(digitalRead(M)==0)
  
    { 
      frontdist_L=data1();
      frontdist_R=data2();
      //Serial.println(frontdist_L);
      //Serial.println(frontdist_R);

        if (digitalRead(drm)==1)//&&(frontdist_R>setdist)&&(frontdist_L>setdist))
            {
              if((digitalRead(LS)==0) && (digitalRead(RS)==0)){forword();}  // Move Forward

              if((digitalRead(LS)==0) && (digitalRead(RS)==1)){left();}     // Turn LEFT
 
              if((digitalRead(LS)==1) && (digitalRead(RS)==0)){right();}    // turn RIGHT
  
              if((digitalRead(LS)==1) && (digitalRead(RS)==1)){Stop();}     // STOP
             }  
        else{Stop();}
      }
      
    if(digitalRead(M)==1)
     
     {
       if((digitalRead(F)==1) || ((digitalRead(F)==1)&&(digitalRead(R)==1))|| ((digitalRead(F)==1)&&(digitalRead(L)==1))){forword();}  // Move Forward

       if(digitalRead(L)==1) {left();}     // Turn LEFT
 
       if(digitalRead(R)==1){right();}    // turn RIGHT
  
       if((digitalRead(B)==1) ||((digitalRead(B)==1)&& (digitalRead(R)==1))||((digitalRead(B)==1)&& (digitalRead(L)==1))){back();} // MOVE BACK
  
       if((digitalRead(F)==0) && (digitalRead(R)==0)&& (digitalRead(L)==0)&& (digitalRead(B)==0)){Stop();}     // STOP
    };
}
/*----------------- Functions------------------*/

long data1()
{
  digitalWrite(TRIG_L,LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_L,HIGH);
  delayMicroseconds(10);
  duration_L=pulseIn(ECO_L,HIGH);
  return duration_L /29/2;
}
long data2()
{
  digitalWrite(TRIG_R,LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_R,HIGH);
  delayMicroseconds(10);
  duration_R=pulseIn(ECO_R,HIGH);
  return duration_R /29/2;
}
void forword()
{
    digitalWrite(LM, HIGH);
    digitalWrite(RM, HIGH);
    digitalWrite(PWM, HIGH);
    digitalWrite(VC, LOW);
    digitalWrite(S, HIGH);
    analogWrite(P, 150);
    delay (500);
}
void left()
{
    digitalWrite(LM, LOW);
    digitalWrite(RM, HIGH);
    digitalWrite(PWM, HIGH);
    digitalWrite(VC, LOW);
    digitalWrite(S, HIGH);
    analogWrite(P, 150);
    delay (500);
}
void right()
{
    digitalWrite(LM, HIGH);
    digitalWrite(RM, LOW);
    digitalWrite(PWM, HIGH);
    digitalWrite(VC, LOW);
    digitalWrite(S, HIGH);
    analogWrite(P, 150);
    delay (500);
}
void Stop()
{
    digitalWrite(PWM, LOW);
    digitalWrite(VC,  HIGH);
    digitalWrite(S, LOW);
    analogWrite(P, 0);
    delay (500);
}
void back()
{
    digitalWrite(LM, LOW);
    digitalWrite(RM, LOW);
    digitalWrite(S, LOW);
    digitalWrite(PWM, HIGH);
    analogWrite(P, 0);
    delay (500);
}
