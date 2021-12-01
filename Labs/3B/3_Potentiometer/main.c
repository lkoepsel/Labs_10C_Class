/* Read the voltage of a Resistor/Light Sensor Circuit and 
* a potentiometer and print range of values from both via the serial port
*/

/* Put your #includes here */
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "unolib.h"
#include "analogRead.h"
#include "uart.h"
/* Put your global variables here */

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/
	init_serial;                

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        // read and display the value on the Light Sensor pin:

        // read and display the value on the Potentiometer pin:

    }
    return(0);
}
