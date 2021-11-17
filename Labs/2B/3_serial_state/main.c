/* Serial_state - show state of FSM by using the serial monitors
/* Put your #includes here */
#include <stdio.h>
#include "uart.h"

/* Put your global variables here */

/* Main */ 
int main() {
/* initialize code goes here */
    int state = 0;
    int number;
    init_serial;                
                
    char input;

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        puts("Enter 0 or 1:");
        input = getchar();
        number = input - '0';
        printf("You entered: %d\n", number);

        if (state == 0) {
            if (number == 0) {
                state = 0;
                puts("Remain in State 0");
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
                puts("Remain in State 1");
                state = 1;
            }
        }
        else if (state == 2) {
            if (number == 0) {
                state = 2;
                puts("Remain in State 2");
            }
            else if (number == 1) {
                state = 3;
                puts("Going to State 3");
            }
        }
        else if (state == 3) {
            if (number == 0) {
                state = 3;
                puts("Remain in State 3");
            }
            else if (number == 1) {
                state = 4;
                puts("Going to State 4");
            }
        }
        else if (state == 4) {
            if (number == 0) {
                state = 5;
                puts("Going to State 5");
            }
            else if (number == 1) {
                state = 4;
                puts("Remain in State 4");
            }
        }
        else if (state == 5) {
            if (number == 0) {
                state = 5;
                puts("Remain in State 5");
            }
            else if (number == 1) {
                state = 1;
                puts("Unlocked!!!");
                return(0);
            }
        }
    }
    return(0);
}
