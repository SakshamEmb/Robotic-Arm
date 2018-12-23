#include <MotorPID.h>


MotorPID motor1(3,22,A0,50);

//MotorPID motor2(5,24,A0,50);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.setPID(0.39,0.01,-0.002);
 // motor2.setPID(0.25,0.039,0.02);

}

void loop() {
  // put your main code here, to run repeatedly:
  int y;
  float angle ;  
  //y = analogRead(A0);
  //angle = map(y,0,1023,0,3600); 
  //Serial.print("Value of pot:");
  //Serial.println(angle);
  motor1.x = 200 ;
 // motor2.x = 600 ; 
  Serial.print("Setpoint: ");
  Serial.println(motor1.x);
  motor1.errorcheck();
  //motor2.errorcheck();
  delay(1000);
  
}
