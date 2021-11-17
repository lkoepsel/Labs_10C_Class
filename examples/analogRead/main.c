#include <stdio.h>
#include "uart.h"
#include <avr/io.h>
#include "delay.h"
#include "unolib.h"
#include "pinMode.h"
#include "analogRead.h"

int main (void)
{
    init_serial;
    uint8_t analog_pin = A4;
    puts("Testing analogRead");
    while(1) {
            printf("Adjust Pot, ");
            printf("value read was: %d\n", analogRead(analog_pin));
            delay(2000);
    }
    return(0);
}
