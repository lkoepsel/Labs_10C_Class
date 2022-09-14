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
    uint8_t photoPin = 0;
    uint8_t potPin = A1;
    uint16_t maxPhoto = 512;
    uint16_t minPhoto = 512;
    uint16_t maxPot = 512;

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/
	init_serial();                

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        // read and display the value on the Light Sensor pin:

        // determine if the value < min or value > max and store if so:

        // read and display the value on the Potentiometer pin:

        // determine if the value < min or value > max and store if so:
        printf("Potcell pin: %d Value: %d Min: %d Max: %d Range: %d\n",\
        potPin, potValue, minPot, maxPot, maxPot-minPot);

    }
    return(0);
}
