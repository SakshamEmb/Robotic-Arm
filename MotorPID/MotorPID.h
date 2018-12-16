#ifndef MotorPID_h

#define MotorPID_h



#include "Arduino.h"



class MotorPID

{

   public:

        MotorPID(int ,int ,char );

        void errorcheck();

        int x;
        
        setPID(float,float,float);
        
        
        

            

    private:

        int dir;

        

        int pwm;
        
        
        char analog ;
        
        
        
        
        void PIDcalculation();
        
        double Kp = 2  ;
        double Ki = 0.39 ;
        double Kd = 0.15 ;

        float last_error = 0;
        float error = 0;
        float changeError = 0;
        float totalError = 0;
        float pidTerm = 0;
        float pidTerm_scaled = 0 ;
        
        int setpoint ;
        
        int angle ;
        
        int pot ;
        
        

    
};



#endif
