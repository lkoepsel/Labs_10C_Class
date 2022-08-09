/* Test the serial monitor by entering numbers
*/
#include <stdio.h>
#include "uart.h"

/* Put your global variables here */

/* Main */ 
int main() {
/* initialize code goes here */
    init_serial();                
    char input;

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        puts("Enter a number");
        input = getchar();
        printf("You entered %c\n", input);        
    }
    return(0);
}
