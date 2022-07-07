/* Finite State Machine Lock - uses a FSM to act as a binary locking mechanism
Requires 3 LEDs/resistors to be connected to pins 3/5/6
Requires 2 push buttons to be connected to pins 10/11 INPUT_PULLUP Mode
Correct button presses will cycle through FSM
Final correct button press will blink all three LEDs
*/

/* Put your #includes here */
#include <stdlib.h>

#include "pinMode.h"
#include "digitalRead.h"
#include "digitalWrite.h"
#include "delay.h"
#include "sysclock.h"
#include "unolib.h"

/* Put your global variables here */
extern button buttons[max_buttons];

/* Main */ 
int main() {
    // state contains the current state of the FSM

    /* initialize buttons to ports, and instantiate using i     */
    /* buttons[i].uno are the Uno pin numbers                         */
    /* buttons[i].pressed indicate the button is pressed   */

    /* It is important to initialize the system clock for the button debounce to work */
    init_sysclock ();

    // Note the resetting of buttons[].pressed, if not there is a race condition
    // when there are two consecutive pushes of the same button
    // the controller will see the first as two pushes and will advance two states
    // by resetting the .pressed variable, it forces the controller to wait for the 2nd push
    while(1) {

        if (state == 0) {
            // Button press 0
            if (buttons[0].pressed) {
                /* code for state 0 button 0 */
            }
            // Button press 1
            if (buttons[1].pressed) {
                /* code for state 0 button 1 */
            }
        }

    }
    return(0);
}
