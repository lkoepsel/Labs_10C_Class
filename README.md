# MPC 10C Labs for the Arduino Using Standard C: Classroom Edition
## Sources
* [This one on Bitbucket](https://bitbucket.org/lkoepsel/10c_labs_class/src/main/)
* [Wellys.com Standard C Documentation](https://www.wellys.com/posts/courses_avr_c/)
* [AVR_C Github Repository](https://github.com/lkoepsel/AVR_C) This link is provided as additional documentation, the Library and examples in AVR_C are included in this repository. It is included in case, someone wants to have a public version available of these files.
## Introduction
This repository is for the classroom using the Arduino Uno, the Standard C tool chain (avr-gcc, avrdude etc) and the Arduino Standard C Library. It includes directories for all of the lab assignments along with examples as to how to use the Arduino Standard C Library. The content is for students who desire understanding Standard C using the Arduino Uno.

Each lab contains multiple folders, each folder is a specific programming exercise. Within each folder is a file called *main.c* and a file called *Makefile*. The file *main.c* is the template for the exercise and the *Makefile* is the required file using *make* to compile/link/load it to an UNO. Think of the *main.c* file as the Arduino IDE sketch and the *Makefile* as a command-line version of the Arduino IDE.

In order to use this content, one must have the AVR-C Standard C tool chain installed on their computer. This [post](https://wellys.com/posts/avr_c_setup/) will advise how to do this on all three platforms, Linux, macOS and Windows. 

Each lab directory also contains the Lab document as well as additional documentation recommended in the Lab.

## Status of the Labs:
- 1B - under review by Instructor
- 2B - under development
- 3B - under development
- 4B - under development
- 5B - under development
- 8B - under development

## Directories
**Note: ./Library and ./examples will be maintained identical to the AVR_C versions**

* examples - contains code demonstrating how to use specific functions in the Library
* Labs - lab content referenced above
* Library - Arduino Standard C Library, specific Arduino functions rewritten in Standard C such as analogRead(), analogWrite(), digitalRead(), and pinMode()