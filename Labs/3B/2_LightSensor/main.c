/* Read the voltage of a Resistor/Light Sensor Circuit and 
* print range of values via the serial port
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
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
                

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        // read the input on an analog pin:
        int sensorValue = analogRead(A5);
        // print out the value you read:
        printf("Analog value was %d\n: ", sensorValue);
        delay(1000);        // delay in between reads for stability

    }
    return(0);
}
