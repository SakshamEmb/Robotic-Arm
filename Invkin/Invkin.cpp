#include "Arduino.h"
#include "Invkin.h"
Invkin::Invkin(float X,float Y,float Z){
    x =  X ;
    y =  Y ;
    z =  Z ;
   
   const float cx=2; //coxa
   const float fm=6.2; //femur
   const float tb=8.3; // tibia 
   
   float L, L1;
   float alpha, alpha1,alpha2,beta,gama;
}

void Invkin::transform()
{
    
trigono_xyz(x,y,z); //contoh x,y,z
Serial.print("gama= ");
Serial.print(gamma);
Serial.print(", alpha= ");
Serial.print(alpha);
Serial.print(", beta= ");
Serial.print(beta);    
Serial.println();
    
}

void Invkin::trigono_xyz(float x, float y, float z)
{
    
 L1=sqrt(sq(x)+sq(y));
    
 gamma=atan(x/y)/PI*180;
    
 L=sqrt(sq(L1-cx)+sq(z));
    
 beta=acos((sq(tb)+sq(fm)-sq(L))/(2*tb*fm))/PI*180;
    
 alpha1=acos(z/L)/PI*180;
    
 alpha2=acos((sq(fm)+sq(L)-sq(tb))/(2*fm*L))/PI*180;
    
 alpha=alpha1+alpha2;
    
 
    
}