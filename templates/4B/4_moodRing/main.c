/* Read and print the analog value off of a thermistor connected to pin A0
*/

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include "unolib.h"
#include "analogRead.h"
#include "pinMode.h"
#include "analogWrite.h"

/* Put your global variables here */
int redPIN = 9;
int greenPIN = 10;
int bluePIN = 11;

/* 
Use to set the LED pins as OUTPUT
*/
void led_OUT() {
    pinMode(redPIN, OUTPUT);
    pinMode(greenPIN, OUTPUT);
    pinMode(bluePIN, OUTPUT);   
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
analogWrite(redPIN, red);
analogWrite(greenPIN, green);
analogWrite(bluePIN, blue);
}

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/
	init_serial();                
    int pinTherm = A0;

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        int valueTherm = analogRead(pinTherm);
        short int red = (valueTherm >> 2);
        short int blue = 255 - red;

        setColor(red, 0, blue);
        printf("Mood is %d/%d\n", red, blue);
        delay(1000);
    }
    return(0);
}
