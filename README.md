# MPC 10C Labs for the Arduino Using Standard C: Classroom Edition
## Getting Started
1. To clone this repository to your system, **follow all of the steps EXACTLY**:

**Note:** [For a more detailed explanation](https://www.wellys.com/posts/avr_c_git/)
```
# open a terminal window in your operating system
# change your directory to where you want to keep this lab
cd Documents
# clone this repository to directory Labs_10C_Class
git clone https://github.com/lkoepsel/Labs_10C_Class.git
# switch to the cloned directory
cd Labs_10C_Class
# copy the templates folder to the new dev folder
cp -r templates dev
```

## Sources
* [This repository](https://github.com/lkoepsel/Labs_10C_Class)
* [Developing in C on the AVR ATmega328P](https://www.wellys.com/posts/courses_avr_c/)
* [AVR_C Github Repository](https://github.com/lkoepsel/AVR_C) This link is provided as additional documentation, the Library and examples in AVR_C are included in this repository. It is included in case, someone wants to have a public version available of these files.
## Introduction
This repository is for the classroom using the Arduino Uno, the Standard C tool chain (avr-gcc, avrdude etc) and the [Arduino Standard C Library](https://github.com/lkoepsel/AVR_C). It includes directories for all of the lab assignments along with examples as to how to use the Arduino Standard C Library. The content is for students who desire understanding Standard C using the Arduino Uno.

Each lab contains multiple folders, each folder is a specific programming exercise. Within each folder is a file called *main.c* and a file called *Makefile*. The file *main.c* is the template for the exercise and the *Makefile* is the required file using *make* to compile/link/load it to an UNO. Think of the *main.c* file as the Arduino IDE sketch and the *Makefile* as a command-line version of the Arduino IDE.

In order to use this content, one must have the AVR-C Standard C tool chain installed on their computer. This [post](https://wellys.com/posts/avr_c_setup/) advises how to do this on all three platforms, Linux, macOS and Windows. 

Each lab directory also contains the Lab document as well as additional documentation recommended in the Lab.

## Directories
**Note: *Library* and *examples* will be maintained identical to the [AVR_C versions](https://github.com/lkoepsel/AVR_C)**

* *examples* - contains code demonstrating how to use specific functions in the Library
* *Labs* - lab content for each class
* *Library* - Arduino Standard C Library, specific Arduino functions rewritten in Standard C such as analogRead(), analogWrite(), digitalRead(), and pinMode()
* *templates* - template directories for each of the lab execises. This directory must be duplicated to be used and called *dev*. **This directory is tracked by git and could be over-written in the next clone operation.**
* *dev* - the student's version of the templates directory, where the students will make changes to the lab files. **This directory is not tracked by git and won't be overwritten.**

## Backup env.make
As *env.make* isn't backed up by git, here is the file's contents. Copy the contents, paste them into a new file then save that file as env.make at the root level of your Labs_10C_Class folder (same level as the *templates/* and *dev/*:
```make
# This file contains the environmental variables to compile/link/load AVR_C
# Only one section may be used at a time, each section describes a specific board
# Comment out the sections which won't be used
# After switching boards, Library must be re-compiled
# Use "make LIB_clean" to force a re-compile of the Library

# Possible Serial Ports on Mac
# /dev/cu.usbserial-01D5BFFC
# /dev/cu.usbmodem5101
# /dev/cu.usbmodem14101

# Possible Serial Ports on Windows
# COM3
# COM4
# COM9

# Arduino UNO and compatible boards
MCU = atmega328p
SERIAL = /dev/cu.usbserial-AR0JYQQB
F_CPU = 16000000UL
BAUD  = 250000UL
SOFT_RESET = 0
LIBDIR = $(DEPTH)Library
PROGRAMMER_TYPE = Arduino
PROGRAMMER_ARGS = -F -V -P $(SERIAL) -b 115200

## Microchip 328PB Xplained Mini environmental variables
# MCU = atmega328pb
# SERIAL = /dev/cu.usbmodem14102
# F_CPU = 16000000UL
# BAUD  = 9600UL
# SOFT_RESET = 0
# LIBDIR = $(DEPTH)Library
# PROGRAMMER_TYPE = xplainedmini
# PROGRAMMER_ARGS = 
```

### Changing Board Types
As the comments in the *env.make* file state, if you switch boards i.e; Uno to Xplained Mini (not Uno to different Uno) then **the Library must be re-compiled**.
Use "*make LIB_clean*" to force a re-compile of the Library followed by a "*make flash*" or copy and paste below into your terminal:
```bash
make LIB_clean && make flash
```
This is also true if you change the *MCU* or *F_CPU*. This only needs to be performed once upon changing boards, *MCU* or *F_CPU*. 
