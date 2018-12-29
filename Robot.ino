#include <MotorPID.h>

int move ; 

MotorPID motor(3,22,A0,50); //shoulder

MotorPID motor1(5,24,A0,50); //elbow

int a ; //Link angle at set up shoulder

int b ; //Link angle at set up elbow

void setup() { put your setup code here, to run once:
  Serial.begin(9600);
  motor1.setPID(0.39,0.01,-0.002);
  motor2.setPID(0.25,0.039,0.02);

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.x = a ;
  motor2.x = b ; 
  
  Serial.println("------Shoulder Motor---------");
  Serial.println(" ");
  motor.errorcheck();
  Serial.println("------Shoulder Motor---------");
  motor1.errorcheck();
  delay(1000);
 Serial.println(" move ?? "); 
 while(!Serial.available()){
 move = Serial.parseInt();

 if(move==0){}
 if(move==1){
  
  motor.x = motor.x + 20 ;

 }
 if(move==2){
  
  motor.x = motor.x - 20 ;

 }
 if(move==3){
  
  motor1.x = motor1.x + 20 ;

 }
 if(move==4){
  
  motor1.x = motor1.x - 20 ;

 }
/* if(move==5){
  
  motor2.x = motor2.x + 20 ;

 }
 if(move==6){
  
  motor2.x = motor.x - 20 ;

 }
  */
  
  
  
}
