/* uart: is not called directly for I/O
*	provides the link between the UNO and the standard C I/O
*	tested and confirmed with puts(), getchar() and printf() 
*	blocking I/O, does not use interrupts, slow 9600 baud
*/

#ifndef UART_H
#define UART_H

int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);

void uart_init(void);

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

#define init_serial() uart_init(); stdout = &uart_output; stdin  = &uart_input;

#endif