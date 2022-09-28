// Use scand to read a string from the serial console

#include <stdio.h>
#include "uart.h"

int main(void) {    

    init_serial();
    
    char input[8];

    puts("Serial I/O Test: String");
    while(1) {
        scanf("%s", input);
        printf("You entered %s\n", input);        
    }        
    return 0;
}
