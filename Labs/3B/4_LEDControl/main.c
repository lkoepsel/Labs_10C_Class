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
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;

    uint8_t PHOTOCELL = A0;
    uint8_t POT = A5;
    uint8_t LED_PHOTO = 9;
    uint8_t LED_POT = 3;                

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        // read the input on an analog pin:
        int sensorValue = analogRead(PHOTOCELL);
        int outputValue = sensorValue >> 2; 
        printf("Photocell value is %d and output value is %d\n ", sensorValue, outputValue);
        analogWrite(LED_PHOTO, 255-outputValue);
        delay(50);        // delay in between reads for stability

        sensorValue = analogRead(POT);
        outputValue = sensorValue >> 2; 
        printf("Potentiometer value is %d and output value is %d\n ", sensorValue, outputValue);
        analogWrite(LED_POT, outputValue);
        delay(50);        // delay in between reads for stability

    }
    return(0);
}
