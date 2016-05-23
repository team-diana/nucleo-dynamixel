#ifndef MBED_MX106_H
#define MBED_MX106_H

#include "mbed.h"
#include "SerialHalfDuplex.h"
#include "communication_1.h"

#define REG_ID 0x3
#define REG_CW_LIMIT 0x06
#define REG_CCW_LIMIT 0x08
#define REG_GOAL_POSITION 0x1E
#define REG_MOVING_SPEED 0x20
#define REG_VOLTS 0x2A
#define REG_TEMP 0x2B
#define REG_MOVING 0x2E
#define REG_POSITION 0x24

 class MX106 {

    public:
    
        MX106(int ID, communication_1& line, float gear_train);
    
        int SetMode(int mode);  
        
        int SetCWLimit(float degrees);
        
        int SetCCWLimit(float degrees);
    
        int GoalPosition(float degrees);

        int SetSpeed(float goal_speed);
    
        float GetTemp(void);
            
    private:
        communication_1& _line;
        float _gear_train;
        int _ID;
        int _mode;    
    };
#endif
