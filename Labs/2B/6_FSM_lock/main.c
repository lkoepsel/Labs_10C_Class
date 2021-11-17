/* Finite State Machine Lock - uses a FSM to act as a binary locking mechanism
Requires 3 LEDs/resistors to be connected to pins 3/5/6
Requires 2 push buttons to be connected to pins 10/11 INPUT_PULLUP Mode
Correct button presses will cycle through FSM
Final correct button press will blink all three LEDs
*/

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>

#include "pinMode.h"
#include "digitalRead.h"
#include "digitalWrite.h"

/* Put your global variables here */

/* Main */ 
int main() {

    // state contains the current state of the FSM
    int state = 0;

    int LED_bit0 = 3;
    int LED_bit1 = 5;
    int LED_bit2 = 6;
    pinMode(LED_bit0, OUTPUT);
    pinMode(LED_bit1, OUTPUT);
    pinMode(LED_bit2, OUTPUT);

    int buttonState0;
    int BUTTON0 = 10;
    int priorState0 = 0;
    pinMode(BUTTON0, INPUT_PULLUP);

    int buttonState1;
    int BUTTON1 = 11;
    int priorState1 = 0;
    pinMode(BUTTON1, INPUT_PULLUP);

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        delay(5);
        buttonState0 = digitalRead(BUTTON0);
        buttonState1 = digitalRead(BUTTON1);

        if (state == 0) {
            // Button press 0
            if (buttonState0 != priorState0) {
                priorState0 = buttonState0;
                if (buttonState0 == LOW) {
                    digitalWrite(LED_bit0, LOW);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, LOW);
                    state = 0;
                }   
            }
            // Button press 1
            if (buttonState1 != priorState1) {
                priorState1 = buttonState1;
                if (buttonState1 == LOW) {
                    digitalWrite(LED_bit0, HIGH);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, LOW);
                    state = 1;
                }
            }
        }
        else if (state == 1) {
            // Button press 0
            if (buttonState0 != priorState0) {
                priorState0 = buttonState0;
                if (buttonState0 == LOW) {
                    digitalWrite(LED_bit0, LOW);
                    digitalWrite(LED_bit1, HIGH);
                    digitalWrite(LED_bit2, LOW);
                    state = 2;
                }
            }
            // Button press 1
            if (buttonState1 != priorState1) {
                priorState1 = buttonState1;
                if (buttonState1 == LOW) {
                    digitalWrite(LED_bit0, HIGH);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, LOW);
                    state = 1;
                }
            }
        }
        else if (state == 2) {
            // Button press 0
            if (buttonState0 != priorState0) {
                priorState0 = buttonState0;
                if (buttonState0 == LOW) {
                    digitalWrite(LED_bit0, LOW);
                    digitalWrite(LED_bit1, HIGH);
                    digitalWrite(LED_bit2, LOW);
                    state = 2;
                }
            }
            // Button press 1
            if (buttonState1 != priorState1) {
                priorState1 = buttonState1;
                if (buttonState1 == LOW) {
                    digitalWrite(LED_bit0, HIGH);
                    digitalWrite(LED_bit1, HIGH);
                    digitalWrite(LED_bit2, LOW);
                    state = 3;
                }
            }
        }
        else if (state == 3) {
            // Button press 0
            if (buttonState0 != priorState0) {
                priorState0 = buttonState0;
                if (buttonState0 == LOW) {
                    digitalWrite(LED_bit0, HIGH);
                    digitalWrite(LED_bit1, HIGH);
                    digitalWrite(LED_bit2, LOW);
                    state = 3;
                }       
            }
            // Button press 1
            if (buttonState1 != priorState1) {
                priorState1 = buttonState1;
                if (buttonState1 == LOW) {
                    digitalWrite(LED_bit0, LOW);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, HIGH);
                    state = 4;
                }
            }
        }
        else if (state == 4) {
            // Button press 0
            if (buttonState0 != priorState0) {
                priorState0 = buttonState0;
                if (buttonState0 == LOW) {
                    digitalWrite(LED_bit0, HIGH);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, HIGH);
                    state = 5;
                }
            }
            // Button press 1
            if (buttonState1 != priorState1) {
                priorState1 = buttonState1;
                if (buttonState1 == LOW) {
                    digitalWrite(LED_bit0, LOW);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, HIGH);
                    state = 4;
                }
            }
        }
        else if (state == 5) {
            // Button press 0
            if (buttonState0 != priorState0) {
                priorState0 = buttonState0;
                if (buttonState0 == LOW) {
                    digitalWrite(LED_bit0, HIGH);
                    digitalWrite(LED_bit1, LOW);
                    digitalWrite(LED_bit2, HIGH);
                    state = 5;
                }
            }
            // Button press 1
            if (buttonState1 != priorState1) {
                priorState1 = buttonState1;
                if (buttonState1 == LOW) {
                    for (int i=0;i<5;i++) {
                        digitalWrite(LED_bit0, HIGH);
                        digitalWrite(LED_bit1, HIGH);
                        digitalWrite(LED_bit2, HIGH);
                        delay(200);
                        digitalWrite(LED_bit0, LOW);
                        digitalWrite(LED_bit1, LOW);
                        digitalWrite(LED_bit2, LOW);
                        delay(200);
                    }
                    return(0);
                }
            }
        }
    }
    return(0);
}
