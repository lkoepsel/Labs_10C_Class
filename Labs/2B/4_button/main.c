/* button - the serial monitor will show the state of the button
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
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
                
    int buttonState;
    int button = 10;
    pinMode(button, INPUT_PULLUP);

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        buttonState = digitalRead(button);
        printf("ButtonState is %d\n", buttonState);
        delay(1000);      
    }
    return(0);
}
