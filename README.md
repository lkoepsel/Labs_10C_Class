# MPC 10C Labs for the Arduino 
### Using *C*: Classroom Edition

## Introduction
This repository is for an introductory course on the *C* language using the Arduino Uno, the *C* tool chain (avr-gcc, avrdude etc) and the [*AVR C Library*](https://github.com/lkoepsel/AVR_C). The content is for students who desire understanding *C* using an embedded microcontroller, in this case the *Arduino Uno R3*. This content uses the *Arduino tool chain* via command line (also called the *terminal*), it doesn't use the Arduino IDE GUI nor does it use the Arduino software framework.  

The directory, *templates*, contains the programs for each lab. Each template folder contains multiple folders, each folder is a specific programming exercise. Within each exercise folder is a file called *main.c* and a file called *Makefile*. The file *main.c* is the template for the exercise and the *Makefile* is the required file using *make* to compile/link/load it to an UNO. Think of the *main.c* file as the Arduino IDE sketch and the *Makefile* as a command-line version of the *Arduino IDE*.

## Dependencies
In order to use this content you **must** have the following installed on your computer:

* **Arduino Legacy IDE (1.8.x)** - Arduino C/C++ tool chain, *installation instructions are below*
* **CoolTerm** - serial monitor, *installation instructions below*
* **Terminal** - command line monitor, *part of operating system*
* **Sublime Text** or **Notepad++** - code editor, *installed by user*

The instructions will refer to specific capabilities such as a *code editor* or *C tool chain*, use the list above to identify the programs associated with the capability.

## Additional Sources of Information

* [Developing in C on the AVR ATmega328P](https://www.wellys.com/posts/courses_avr_c/) A series of web pages explaining in detail how to use specific aspects of the AVR C software framework.
* [AVR_C Github Repository](https://github.com/lkoepsel/AVR_C) The repository link is provided for additional documentation. The *AVR C Library* and *examples* are included in the *MPC 10C Labs* repository.
* [AVR LibC](https://www.nongnu.org/avr-libc/) This library is the basis for the *C*language for the AVR. From GNU "*AVR Libc is a Free Software project whose goal is to provide a high quality C library for use with GCC on Atmel AVR microcontrollers.*" 

## Directories
**Note: *Library* and *examples* will be maintained identical to the [AVR_C versions](https://github.com/lkoepsel/AVR_C)**

* *examples* - contains code demonstrating how to use specific functions in the Library
* *Library* - *AVR C Library*, specific Arduino functions rewritten in *C* such as analogRead(), analogWrite(), digitalRead(), and pinMode()
* *templates* - template directories for each of the lab execises. This directory must be duplicated to be used and called *dev*. **This directory is tracked by git and could be over-written in the next clone operation.**
* *dev* - the student's version of the templates directory, where the students will make changes to the lab files. **This directory is not tracked by git and won't be overwritten.**

## Installation
### 1. Copy repository
This step will add the lab programming content to your system. You will download the repository as a zip file, extract it and copy to your Documents directory.

#### To download and extract
1. Click on the green button **<> Code** on the [repository](https://github.com/lkoepsel/Labs_10C_Class) page.
1. With the tab showing "*Local*", got to the bottom option, Download ZIP.
1. Once downloaded, right click to either *"Open with Archive Utility" (macOS)* or *Extract All... (Windows)*
1. Move the folder extracted to your *Documents* directory.
1. Duplicate the *templates* folder and call it *dev*

### 2. Create env.make
As *env.make* isn't backed up by git, you will need to create one. Use your code editor and copy the contents then paste them into a new file. Save that file as env.make at the root level of your Labs_10C_Class folder (same level as the *templates/* and *dev/*:
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

# Options for TOOLCHAIN are 'arduino' or blank
# Options for OS are 'mac' or 'windows'

# Arduino UNO and compatible boards
MCU = atmega328p
SERIAL = /dev/cu.usbmodem3101
F_CPU = 16000000UL
BAUD  = 250000UL
SOFT_RESET = 0
LIBDIR = $(DEPTH)Library
PROGRAMMER_TYPE = Arduino
PROGRAMMER_ARGS = -F -V -P $(SERIAL) -b 115200
TOOLCHAIN = arduino
OS = mac

## Microchip 328PB Xplained Mini environmental variables
# MCU = atmega328pb
# SERIAL = /dev/cu.usbmodem14102
# F_CPU = 16000000UL
# BAUD  = 9600UL
# SOFT_RESET = 0
# LIBDIR = $(DEPTH)Library
# PROGRAMMER_TYPE = xplainedmini
# PROGRAMMER_ARGS = 
# TOOLCHAIN = 
# OS = mac
```

You will need to set the following:
* **SERIAL =** to the serial port you found using the Arduino IDE
* **TOOLCHAIN = arduino** delete the word 'arduino if you wish to use the locally installed GNU C tool chain'
* **OS = mac** replace 'mac' with 'windows' if on a Windows PC
### 3. CoolTerm
Install or confirm *CoolTerm* is installed on your system. It is a multi-platform serial monitor, for free, and has phenomenal scripting capabilities as well.

**ONLY DOWNLOAD FROM THIS SITE:**

https://freeware.the-meiers.org      **Confirm the URL in your browser!**

**AND** after downloading *CoolTerm* and before installing, please take [one more step](/posts/serial_applications/#install) to confirm the image is the proper one. Roger Meier has done a great job in providing the **checksums for the latest releases**. 

### Changing Board Types
As the comments in the *env.make* file state, if you switch boards i.e; Uno to Xplained Mini (not Uno to different Uno) then **the Library must be re-compiled**.
Use "*make LIB_clean*" to force a re-compile of the Library followed by a "*make flash*" or copy and paste below into your terminal:
```bash
make LIB_clean && make flash
```
This is also true if you change the *MCU* or *F_CPU*. This only needs to be performed once upon changing boards, *MCU* or *F_CPU*. 
