
#include <ros.h>
#include <geometry_msgs/Point.h>

#include "Invkin.h"
#include "MotorPID.h"

float X ;
float Y ;
float Z ;
float x ;
float y ;
float z ;

ros::NodeHandle node;
geometry_msgs::Point msg;

MotorPID M1(3,22,A0);

Invkin IK(2,4,6);



void roverCallBack(const geometry_msgs::Point& co_ordinates)
{  
    X =   co_ordinates.x ;
    Y =   co_ordinates.y ;  
    Z =   co_ordinates.z ;
    Serial.println(X);
   
}



ros::Subscriber <geometry_msgs::Point> sub("co_ordinates", &roverCallBack);

void setup()
{
  Serial.begin(115200);  
  node.getHardware()->setBaud(115200);
  node.initNode();
  node.subscribe(sub);
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  pinMode(22,OUTPUT);
  M1.setPID(0.5,0.02,0.02);
  

  
} 

void loop()
{
   IK.transform(); 
  M1.x = IK.theta1 ;
  int m = analogRead(A0);
  Serial.println(M1.x);
  Serial.println(map(m,0,1023,0,3600));
  
  
  
  M1.errorcheck();
    
  node.spinOnce(); 
  delay(1000);
}
