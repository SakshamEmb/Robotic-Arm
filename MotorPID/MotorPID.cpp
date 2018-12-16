#include "Arduino.h"
#include "MotorPID.h"


MotorPID::MotorPID(int pin1 , int pin2 , char m) {
  //pinMode(2, INPUT);//encoder pins
  pinMode(pin1, OUTPUT);
    
  pinMode(m,INPUT);
  //pinMode(dir1, OUTPUT);
  pinMode(pin2, OUTPUT);
    
  pwm = pin1 ;
        
  dir = pin2 ;
    
  analog = m ;        
    
    
}


void MotorPID::errorcheck(){
    

    
  int pot = analogRead(analog);  
    
  setpoint = x ;    
  angle = map(pot,0,1023,0,3600); //count to angle conversion 
    
  //Serial.println(angle);  
    
  setpoint = x ;     

  PIDcalculation();// find PID value 
  
  if (angle < setpoint) {
    digitalWrite(dir, LOW);// Forward motion
    //digitalWrite(dir, HIGH);
    analogWrite(pwm, pidTerm_scaled);
  }
    
  else  {
    digitalWrite(dir, HIGH);//Reverse motion
    //digitalWrite(dir2, LOW);
    analogWrite(pwm, pidTerm_scaled);
  }   
  //Serial.println(pidTerm_scaled);  
  //delay(100);
}

void MotorPID::PIDcalculation(){
    
  error = setpoint - angle;  
  changeError = error - last_error; // derivative term
  totalError += error; //accumalate errors to find integral term
  pidTerm = (Kp * error) + (Ki * totalError) + (Kd * changeError);//total gain
  pidTerm = constrain(pidTerm, -255, 255); //constraining to appropriate value
  pidTerm_scaled = abs(pidTerm); //to make sure it's a positive value
  last_error = error;

}


/*void MotorPID::setPID(float kp , float ki , float kd){
    
    Kp = kp ;
    
    Ki = ki ;
    
    Kd = kd ;
    
    
}*/ 
