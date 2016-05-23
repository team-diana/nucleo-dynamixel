#include "MX106.h"
#include "mbed.h"

//360°/4095
#define RESOLUTION 0.088
//bit per degrees 4095/360°
#define BIT_DEG 11.375

#define READ_DEBUG 1

MX106::MX106(int ID, communication_1& line, float gear_train)
	: _line(line)
	, _gear_train(gear_train)
    , _ID(ID)
	{}


int MX106::SetMode(int mode) {
    switch (mode){
        //Wheel Mode
        case (0): 
            SetCWLimit(0);
            SetCCWLimit(0);
            SetSpeed(0.0);
            _mode = mode; 
            break;
        //Joint Mode
        case (1): 
            SetCWLimit(RESOLUTION);
            SetCCWLimit(RESOLUTION);
            SetSpeed(0.0);
            _mode = mode;
            break;
        //Multi-turn Mode 
        case (2): 
            SetCWLimit(360);
            SetCCWLimit(360);
            SetSpeed(0.0);
            _mode = mode;
            break;
        //other cases
        default: 
            if(READ_DEBUG){
            printf("Not valid mode"); 
            }
    }
    return(0);
}


int MX106::SetCWLimit(float degrees) {
     
    char data[2];
    
    short limit = (short)(BIT_DEG * degrees * _gear_train);

    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits

    // write the packet, return the error code
    return(_line.write(_ID, REG_CW_LIMIT, 2, data));
}


int MX106::SetCCWLimit(float degrees) {
     
    char data[2];
    
    short limit = (short)(BIT_DEG * degrees * _gear_train);

    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits

    // write the packet, return the error code
    return(_line.write(_ID, REG_CCW_LIMIT, 2, data));
}


int MX106::GoalPosition(float degrees) {
    
    char data[2];
    
    short gaol_position = (short)(BIT_DEG * degrees * _gear_train);

    data[0] = gaol_position & 0xff; // bottom 8 bits
    data[1] = gaol_position >> 8;   // top 8 bits

    // write the packet, return the error code
    return(_line.write(_ID, REG_GOAL_POSITION, 2, data));
}


int MX106::SetSpeed(float goal_speed) {

    // bit 10     = direction, 0 = CCW, 1=CW
    // bits 9-0   = Speed
    char data[2];

    int goal = (0x3ff * fabsf(goal_speed * _gear_train));

    // Set direction CW if we have a negative speed
    if (goal_speed < 0) {
        goal |= (0x1 << 10);
    }

    data[0] = goal & 0xff; // bottom 8 bits
    data[1] = goal >> 8;   // top 8 bits
    
    // write the packet, return the error code
    return(_line.write(_ID, REG_MOVING_SPEED, 2, data));
}


float MX106::GetTemp(void) {
    char data[1];
    int ErrorCode = _line.read(_ID, REG_TEMP, 1, data);
    float temp = data[0];
    return(temp);
}
