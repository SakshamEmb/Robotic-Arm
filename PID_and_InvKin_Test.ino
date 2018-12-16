#include "Invkin.h"
#include "MotorPID.h"


Invkin IK(5,40,10);

MotorPID motor1(3,2,A0);

MotorPID motor2(10,8,A1);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);  
 IK.transform();

}

void loop() {
  // put your main code here, to run repeatedly: 

  motor1.x = IK.alpha ;

  motor1.errorcheck();

  motor2.x = IK.beta ;

  motor2.errorcheck();
  

   
 
}

