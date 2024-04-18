[TOC]
Introduction
============
WY_Logger is a C library that provides a simple API to log messages of the form:

\[Date and Time\]: Message

This library has the following key characteristics:
- Supports printf() and fprintf() style APIs.
- Include or exclude timestamps in logs.
- Supports UTC time offsets.
- Supports logging to stdout as well as to files simultaneously.
- Uses the MIT license so it is easy to integrate into any application.

File Organisation
=================
There are 3 directories in the base directory: 

src: Contains all source code files. <br>

build: Contains the following:
- The Makefile. 
- After compilation, all object, library and demo files will be in this directory. 

doc: Contains the following:
- A README.md and Doxyfile used by doxygen.
- By running doxygen using the provided Doxyfile, all HTML documentation will be generated in this directory.

Compilation and Usage
=====================
Build the library and demo application by entering the build directory and entering "make". This generates:
1. A library lib_WY_Logger.a.
2. A demo application compiled from demo.c named demo.

The supplied Makefile defaults to using the following compiler flags. Modify them as required to suit your own build system.<br>
`CFLAGS = -std=c17 -Wall -Wextra -O3 -flto` <br>
`ARCH = -march=native` <br>
**NOTE**: Obviously the `-flto` and `-march=native` options must be changed where necessary! 

To clean up object files, run `make clean`. To clean up all files including library files and the demo application, run `make distclean`.

How to use the library:
1. Include WY_Logger.h in your code. 
2. Link to lib_WY_Logger.a in your build.
3. And that's it.

For an example, refer to demo.c. This is the best guide to using the library.

Demo application
================
The demo application writes to a log file "log.txt" within the build directory by default.

demo.c is easy to read and understand - there is not much more to say about it.

Implementation Details
======================
 
-# Always call wy_logger_init() to initialise the internal buffers and time offset in the library.
-# A buffer size limit must be specified in wy_logger_init() to ensure logging and memory management sanity.
-# The creation of files for logging is excluded from within the library as the function call is so trivial. This also allows applications to create multiple log files and use the WY_Logger library to log to them.
-# Call wy_logger_clean() to clean up all internal buffers when processing is completed.
