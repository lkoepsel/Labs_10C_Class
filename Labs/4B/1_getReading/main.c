/* Read and print the analog value off of a thermistor connected to pin A0
*/

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include <unolib.h>
#include <analogRead.h>

/* Put your global variables here */

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
                
    int pinTherm = A0;

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        int valueTherm = analogRead(pinTherm);
        printf("Reading is: %d\n", valueTherm);
        delay(1000);
    }
    return(0);
}
