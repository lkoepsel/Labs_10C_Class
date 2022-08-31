/*  LED - configure and test 3 LED circuits

Based on 1_blink which blinks the pin 13 internal LED

*/

#include "unolib.h"
#include "pinMode.h"
#include "digitalWrite.h"
#include "delay.h"
 
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
        delay(500);
         // wait for a 1/2 second
        digitalWrite(LED, LOW);
         // turn the LED off by making the voltage LOW
        delay(500);
         // wait for a 1/2 second
    }


    return 0;
}
