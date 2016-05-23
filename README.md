# nucleo-dynamixel
Library for working with dynamixel servomotors, designed for stm32  nucleo boards

## Usage example

```
#include "MX106.h"
#include "communication_1.h"

communication_1 wire(PA_9, PA_10, 9600);
MX106 motor_21(21, wire, 1);
MX106 motor_22(22, wire, 1);


int main() {
   // set speed mode
   motor_21.SetMode(0);
   // set joint mode
   motor_22.SetMode(1);
   // Set new motor speed. The motor will move continously at this speed
   motor_21.SetSpeed(0.25);
   // Set new motor position. The motor will reach 180 degrees and then stop
   motor_22.GoalPosition(180);

}

```

## Document the code

See existing documentation, use the same format. Use the \\brief, \\param, \\return keywords

Read also https://www.rosettacommons.org/docs/latest/development_documentation/tutorials/doxygen-tips

## Update doxygen

```bash
# in the project directory
# update doxygen html files
doxygen
# commit changes
git push origin master
# push update on gh-pages
git subtree push --prefix docs/html origin gh-page
```
