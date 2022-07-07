/* Binary - enter a number in the serial monitor and three LEDs will
* show it in binary (0-7)
*/

/* Put your #includes here */
#include <stdio.h>
#include "uart.h"
#include "pinMode.h"
#include "unolib.h"
#include "digitalWrite.h"

/* Put your global variables here */

/* Main */ 
int main() {
/* initialize code goes here */
    init_serial;                
                
    char input;
    int bit0 = 3;
    int bit1 = 5;
    int bit2 = 6;
    pinMode(bit0, OUTPUT);
    pinMode(bit1, OUTPUT);
    pinMode(bit2, OUTPUT);

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        puts("Enter a number:");
        input = getchar();
        int number = input - '0';
        
        if (number == 0) {
            digitalWrite(bit0, LOW);
            digitalWrite(bit1, LOW);
            digitalWrite(bit2, LOW);
        }
        else if (number == 1) {
            digitalWrite(bit0, HIGH);
            digitalWrite(bit1, LOW);
            digitalWrite(bit2, LOW);
        }
    }
    return(0);
}
