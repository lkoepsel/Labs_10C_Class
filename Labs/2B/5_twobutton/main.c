/* twobutton - show a count for two buttons via the serial monitor
/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include "pinMode.h"
#include "digitalRead.h"

/* Put your global variables here */

/* Main */ 
int main() {
/* initialize code goes here */
	init_serial;                
    int buttonState0;
    int button0 = 10;
    int priorState0 = 0;
    int count0 = 0;
    pinMode(button0, INPUT_PULLUP);

    int buttonState1;
    int button1 = 11;
    int priorState1 = 0;
    int count1 = 0;
    pinMode(button1, INPUT_PULLUP);


// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        delay(5);
        buttonState0 = digitalRead(button0);
        buttonState1 = digitalRead(button1);
        if (buttonState0 != priorState0) {
            priorState0 = buttonState0;
            if (buttonState0 == LOW) {
                count0 += 1;
                printf("Count0 = %d\n", count0);
            }
        }
        if (buttonState1 != priorState1) {
            priorState1 = buttonState1;
            if (buttonState1 == LOW) {
                count1 += 1;
                printf("Count1 = %d\n", count1);
            }
        }
    }
    return(0);
}
