// Serial I/O test
// Requires serial monitor set to 9600, 8, 1, None with no line ending
// Use Arduino Serial Monitor, CoolTerm, PUTTY or your favorite serial monitor
#include <stdio.h>
#include "uart.h"

int main(void) {    
    init_serial();
    int input;

    puts("Serial I/O Test: Enter a character");
    while(1) {
        input = getchar();
        putchar(input);
        printf(" You entered the character %c, ", input);
        printf("%i in ASCII decimal, %x in ASCII hex\n", input, input);        
    }
    return 0;
}
