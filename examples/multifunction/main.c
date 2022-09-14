/* One line kernal for multitasking
*  https://www.embedded.com/a-multitasking-kernel-in-one-line-of-code-almost/
*  Uses direct pin manipulation using a set bit on Input Port
*  Delivers 81kHz signal from 8 tasks
*  Delivers 207kHz signal from 3 tasks
*/

#include <avr/io.h>
#include "delay.h"
#define NTASKS 3

// Uno pin numbers
const uint8_t LED0 = 3; 
const uint8_t LED1 = 5;
const uint8_t LED2 = 6;
const uint8_t LED3 = 5;
const uint8_t LED4 = 6;
const uint8_t LED5 = 7;
const uint8_t LED6 = 0;
const uint8_t LED7 = 1;

typedef struct task {
   void (*TickFct)();    // Function to call for task's tick
} task;

task tasks[NTASKS];

void t0 (void) {
    /* toggle led on and off */
    PIND |= _BV(LED0);
    return;
} 

void t1 (void) {
    /* toggle led on and off */
    PIND |= _BV(LED1);
    return;
} 

void t2 (void) {
    /* toggle led on and off */
    PIND |= _BV(LED2);
    return;
} 

void t3 (void) {
    /* toggle led on and off */
    PIND |= _BV(LED3);
    return;
} 

void t4 (void) {
    /* toggle led on and off */
    PIND |= _BV(LED4);
    return;
} 

void t5 (void) {
    /* toggle led on and off */
    PIND |= _BV(LED5);
    return;
} 

void t6 (void) {
    /* toggle led on and off */
    PINB |= _BV(LED6);
    return;
} 

void t7 (void) {
    /* toggle led on and off */
    PINB |= _BV(LED7);
    return;
} 


int main(void)
{
    DDRD |= _BV(LED0) | _BV(LED1) | _BV(LED2)  | _BV(LED3) | _BV(LED4) | _BV(LED5);
    DDRB |= _BV(LED6) | _BV(LED7) ;

    uint8_t i = 0;
    tasks[i].TickFct = &t0;
    ++i;
    tasks[i].TickFct = &t1;
    ++i;
    tasks[i].TickFct = &t2;
    ++i;
    tasks[i].TickFct = &t3;
    ++i;
    tasks[i].TickFct = &t4;
    ++i;
    tasks[i].TickFct = &t5;
    ++i;
    tasks[i].TickFct = &t6;
    ++i;
    tasks[i].TickFct = &t7;

    for (;;)
    {
    for (int8_t taskcount=0; taskcount < NTASKS; ++taskcount)
        {
            tasks[taskcount].TickFct();
        }
    }
    return(0); 
}
