/*
Blink
Same as Arduino Blink sketch, blinks the built-in LED
*/

#include "unolib.h"
#include "pinMode.h"
#include "digitalWrite.h"
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int LED = 13;
// C code must have a main function, it is the primary code in the file
int main() {

    // initialize the digital pin as an output.
    pinMode(LED, OUTPUT);

    // a while(1) loop runs over and over again forever:
    while(1) {
        digitalWrite(LED, HIGH);
         // turn the LED on (HIGH is the voltage level)
        delay(1000);
         // wait for a second
        digitalWrite(LED, LOW);
         // turn the LED off by making the voltage LOW
        delay(250);
         // wait for a second
    }
    // return(0) isn't used, however required for strict C compilation
    return(0);
}
