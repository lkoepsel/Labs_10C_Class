/* Read the voltage of a:
    Photocell and adjust the LED inversely (brighter light dims LED)
    Potentiomenter and adjust the LED (lower voltage dims LED)
    and print the values of the sensor and the LED for both via the serial port
*/

/* Put your #includes here */
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "unolib.h"
#include "analogRead.h"
#include "uart.h"
#include "analogWrite.h"
/* Put your global variables here */

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute

    }
    return(0);
}
