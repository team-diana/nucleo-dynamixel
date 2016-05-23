#ifndef __COMMUNICATION_1_H__
#define __COMMUNICATION_1_H__

#include "mbed.h"
#include "SerialHalfDuplex.h"

/**
*\brief This class handle communication with dynamixel products that use the Communication 1 protocol 
*
*This class handle communication with dynamixel products that use the Communication 1 protocol 
*http://support.robotis.com/en/product/dynamixel/dxl_communication.htm
*It uses a SerialHalfDuplex port. 
*/


class communication_1 {
public:
    /**
    * \brief Create a communication_1
    * \param tx pin for tx, elettrically connected to rx
    * \param rx pin for rx, elettrically connected to tx
    * \param baud_rate  as defined in the dynamixel documentation (e.g. 9600)
    */
    communication_1(PinName tx, PinName rx, int baud_rate);
    
    int read(int ID, int start, int length, char* data);
    int write(int ID, int start, int length, char* data, int flag=0);

private:
    SerialHalfDuplex _SerialHalfDuplex;
};

#endif
