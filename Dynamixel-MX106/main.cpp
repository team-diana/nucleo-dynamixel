#include "mbed.h"
#include "MX106.h"
#include "communication_1.h"

/*Connessioni jupers millefori/nucleo:
    - rosso 5V
    - nero GND
    - marrone D2
    - verde D8
  Il connettore va stacato dal dynamixel e non dalla millefori per non scambiare il verso!*/

Serial pc(USBTX, USBRX);
communication_1 wire(PA_9, PA_10, 9600);
MX106 motor_21(21, wire, 1);
MX106 motor_22(22, wire, 1);


int main() {
   pc.printf("Start run! \n");
   motor_21.SetMode(0);
   motor_22.SetMode(0);
   motor_22.SetSpeed(0.25);

}
