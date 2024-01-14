# MPC 10C Labs for the Arduino 
### Using *C*: Classroom Edition

## Introduction
This repository is for the classroom using the Arduino Uno, the *C* tool chain (avr-gcc, avrdude etc) and the [*AVR C Library*](https://github.com/lkoepsel/AVR_C). It includes directories for all of the lab assignments along with examples as to how to use the *AVR C* Library. The content is for students who desire understanding *C* using the *Arduino Uno*.

Each lab contains multiple folders, each folder is a specific programming exercise. Within each folder is a file called *main.c* and a file called *Makefile*. The file *main.c* is the template for the exercise and the *Makefile* is the required file using *make* to compile/link/load it to an UNO. Think of the *main.c* file as the Arduino IDE sketch and the *Makefile* as a command-line version of the *Arduino IDE*.

In order to use this content, one must either use the *Arduino tool chain* via command line or have the *GNU C tool chain* installed on their computer. This [post](https://wellys.com/posts/avr_c_setup/) advises how to do either of these tasks on all three platforms, Linux, macOS and Windows. 

## Dependencies
In order to use this content you **must** have the following installed on your computer:

* **Arduino Legacy IDE (1.8.x)** - C tool chain, *instructions are below*
* **Cool Term** - serial monitor, *instructions below*
* **Terminal** - command line monitor, *part of operating system*
* **Sublime Text** or **Notepad++** - code editor, *installed by user*

The instructions will refer to specific capabilities such as a *code editor* or *C tool chain*, use the list above to identify the programs associated with the capability.

## Sources
* [This repository](https://github.com/lkoepsel/Labs_10C_Class)
* [Developing in C on the AVR ATmega328P](https://www.wellys.com/posts/courses_avr_c/)
* [AVR_C Github Repository](https://github.com/lkoepsel/AVR_C) This link is provided as additional documentation, the Library and examples in AVR_C are included in this repository. It is included in case, someone wants to have a public version available of these files.

## Directories
**Note: *Library* and *examples* will be maintained identical to the [AVR_C versions](https://github.com/lkoepsel/AVR_C)**

* *examples* - contains code demonstrating how to use specific functions in the Library
* *Library* - AVR *C* Library, specific Arduino functions rewritten in *C* such as analogRead(), analogWrite(), digitalRead(), and pinMode()
* *templates* - template directories for each of the lab execises. This directory must be duplicated to be used and called *dev*. **This directory is tracked by git and could be over-written in the next clone operation.**
* *dev* - the student's version of the templates directory, where the students will make changes to the lab files. **This directory is not tracked by git and won't be overwritten.**

## Installation
### 1. Copy repository
This step will add the lab programming content to your system. If you have git (*or want to learn how to use git*) install [git on your system](/posts/avr_c_git/). You may also simply download the repository as a zip file, extract it and copy to your Documents directory.

#### To download and extract
1. Click on the green button **<> Code** on the [repository](https://github.com/lkoepsel/Labs_10C_Class) page.
1. With the tab showing "*Local*", got to the bottom option, Download ZIP.
1. Once downloaded, right click to either *"Open with Archive Utility" (macOS)* or *Extract All... (Windows)*
1. Move the folder extracted to your *Documents* directory.
1. Duplicate the *templates* folder and call it *dev*

#### To use git
Clone this repository to your system, **follow all of the steps EXACTLY**:

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
### 2. Change Makefile to Use Arduino Tool Chain
The *Makefile* has a variable `TOOLCHAIN = `, which allows you to use either, a system-installed toolchain (default, *GNU C tool chain*) or the toolchain installed by the legacy *Arduino (1.8.x) IDE*. 

In order to use the latter, perform the following steps:
1. In your code editor, open the *Makefile* in the root directory, as in *Labs_10C_Class/Makefile*.
1. Add *arduino* to the `TOOLCHAIN` variable as in `TOOLCHAIN = arduino`
1. Uncomment, by removing the leading `# ` *(this is pound sign **AND** the following space)* from the lines `BIN = ...` and `AVRDUDECONF = ...` lines appropriate to your operating system

**Below is an example of the directions, using a Windows PC:**
```bash
# Change the line below to TOOLCHAIN = arduino, if you want to use the Arduino IDE tools
# And uncomment the appropriate block of code based on your OS
TOOLCHAIN = arduino
ifeq ($(TOOLCHAIN), arduino)
	# macOS lines, remove both the # and the following space
	# BIN = /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/
	# AVRDUDECONF = -C /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/bootloaders/gemma/avrdude.conf

	# Windows lines, remove both the # and the following space
	BIN = 'C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\'
	AVRDUDECONF = '-CC:\Program Files (x86)\Arduino\hardware\arduino\avr\bootloaders\gemma\avrdude.conf'	
else
	BIN =
	AVRDUDECONF = 
endif
```
**The `BIN = ...` and `AVRDUDECONF = ...` lines must be indented only with a `tab` at the beginning of the line for make to accept the lines.**

### 3. Create env.make
As *env.make* isn't backed up by git, you will need to create one. Again, use your code editor. Copy the contents then paste them into a new file. Save that file as env.make at the root level of your Labs_10C_Class folder (same level as the *templates/* and *dev/*:
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
### 4. CoolTerm
Install or confirm CoolTerm is installed on your system. It is a Multi-platform serial monitor, for free and has phenomenal scripting capabilities as well.

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
