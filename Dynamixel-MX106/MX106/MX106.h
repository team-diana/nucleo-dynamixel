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

/**
 * \brief Control a single MX106 motor
 *
 * This class controls a single MX106 motor. Using this class you can control position, movement, and other parameters.
 */

 class MX106 {

    public:
    
        /** 
        * \brief Create a MX106 instance
        * \param ID unique ID of the dynamixel motor
        * \param line communication_1 instance, used for communicating with the motor
        * \param gear_train gear ratio
				*/
        MX106(int ID, communication_1& line, float gear_train);
    
        
				/** \brief Set the motor mode
				* \param mode  
 				* mode=0 wheel mode: continous rotaton, like speed control
 				* mode=1 joint mode: like position control, from 0 to 360 degrees
 				* mode=2 multiturn mode: like position control, allows multiple rotation, more than 360 degrees
				*/
        int SetMode(int mode);  
        
        int SetCWLimit(float degrees);
        
        int SetCCWLimit(float degrees);
    
				/**
				* \brief Set the goal position that the motor will reach
				* \param degrees the position, in degree.   
				*/
        int GoalPosition(float degrees);

				/** 
        * \brief Set the maximum speed used during movement. Motor will try to reach this speed.
				* \param goal_speed  speciefied as  TODO: specify
				*/
        int SetSpeed(float goal_speed);
    
				/** 
				* \brief Get current temperature of the motor
				* \return current temperature of the motor
				*/
        float GetTemp(void);
            
    private:
        communication_1& _line;
        float _gear_train;
        int _ID;
        int _mode;    
    };
#endif
