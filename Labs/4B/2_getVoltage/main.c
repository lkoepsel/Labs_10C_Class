/* Read and print the analog value off of a thermistor connected to pin A0
* then convert that reading into a voltage and print
* NOTE:
* math lib and vprintf must be included when compiled, 
* be sure next line is uncommented in  Makefile
* LDFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
*/

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "uart.h"
#include <unolib.h>
#include <analogRead.h>


double getVoltage(int reading) {
    double voltage = reading * (5/1024.0);
    return(voltage);
}

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

        double voltageTherm = getVoltage(valueTherm);
        printf("Reading is: %fF\n", voltageTherm);
        delay(1000);
    }
    return(0);
}
