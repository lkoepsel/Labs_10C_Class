# Environmental variables for specific boards
# After switching boards, Library must be re-compiled
# Use "make LIB_clean" to force a re-compile of the Library

# Microchip 328PB Xplained Mini board
# MCU = atmega328pb
# SERIAL = /dev/cu.usbmodem3102
# F_CPU = 16000000UL  
# BAUD  = 9600UL
# SOFT_RESET = 1
# LIBDIR = ../../Library
# PROGRAMMER_TYPE = xplainedmini
# PROGRAMMER_ARGS = 

# Arduino UNO and compatible boards
MCU = atmega328p
SERIAL = /dev/cu.usbmodem3101
F_CPU = 16000000UL  
BAUD  = 9600UL
SOFT_RESET = 0
LIBDIR = ../../../Library
PROGRAMMER_TYPE = Arduino
PROGRAMMER_ARGS = -F -V -P $(SERIAL) -b 115200
