/* Binary - enter a decimal number (0-7) in the serial monitor 
* and three LEDs will show it in binary (000 - 111)
*
* ASSUMPTIONS: LEDs are connected to pins 2, 4 and 6
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
    init_serial();                
                
    char input;
    int bit0 = 2;
    int bit1 = 4;
    int bit2 = 6;
    pinMode(bit0, OUTPUT);
    pinMode(bit1, OUTPUT);
    pinMode(bit2, OUTPUT);

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        puts("Enter a number:");
        input = getchar();
        int number = 0; // FIX ME -- convert input to int format according to instructions in Lab Handout
        
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
		// FIX ME -- add additional sections to process numbers 2 - 7
		
		
		
		
		
    }
    return 0;
}
