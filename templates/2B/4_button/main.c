/* button - the serial monitor will show the state of the button */
/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "uart.h"
#include "pinMode.h"
#include "digitalRead.h"

/* Put your global variables here */

/* Main */ 
int main() {
/* initialize code goes here */
    int buttonState;
    int button = 10;

    init_serial();
    pinMode(button, INPUT_PULLUP);

// while(1) loop routine runs over and over again forever:
    while(1) {
        buttonState = digitalRead(button);
        printf("ButtonState is %d\n", buttonState);

        delay(1000);
    }
    return(0);
}
