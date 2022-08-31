/* Serial_state - show state of FSM by using the serial monitors
/* Put your #includes here */
#include <stdio.h>
#include "uart.h"

/* Put your global variables here */

/* Main */ 
int main() {
/* initialize code goes here */
    init_serial();                
                

// while(1) loop routine runs over and over again forever:
    while(1) {
		printf("Currently in state %d, state);
        /* Print a line of text requesting a 0 or 1 */
        /* then input the character and make it an integer */
        puts("Enter 0 or 1:");
        printf("You entered: %d\n", number);

        if (state == 0) {
            if (number == 0) {
                state = 0;
            }
            else if (number == 1) {
                state = 1;
                puts("Going to State 1");
            }
        }
        else if (state == 1) {
            if (number == 0) {
                state = 2;
                puts("Going to State 2");
            }
            else if (number == 1) {
            }
        }
		// FIX ME -- continue adding code for states 0-6
		// 
    }
    return 0;
}
