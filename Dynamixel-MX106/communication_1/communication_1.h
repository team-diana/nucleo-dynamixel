#ifndef __COMMUNICATION_1_H__
#define __COMMUNICATION_1_H__

#include "mbed.h"
#include "SerialHalfDuplex.h"

class communication_1 {
public:
    communication_1(PinName tx, PinName rx, int baud_rate);
    
    int read(int ID, int start, int length, char* data);
    int write(int ID, int start, int length, char* data, int flag=0);

private:
    SerialHalfDuplex _SerialHalfDuplex;
};

#endif
