NAME: Forrest Burton
EMAIL: burton.forrest10@gmail.com
ID: 005324612


Files included:
lab0.c - A C file which  copies it standard input to standard output, and supports the following arguments:
--input=filename ... use the specified file as standard input 
If you are unable to open the specified input file, report the failure
--output=filename ... create the specified file and use it as standard output 
If you are unable to create the specified output file, report the failure
--segfault ... force a segmentation fault
--catch ... use signal(2) to register a SIGSEGV handler that catches the segmentation fault

Makefile - Supports:
(default) ... build the lab0 executable. 
check ... runs a quick smoke-test on whether or not the program seems to work
clean ... delete all files created by the Makefile, and return the directory to its freshly untared state.
dist ... build the distribution tarball.

backtrace.png - a segfault and associated stack-trace

breakpoint.png - a breakpoint and variable inspection

Smoke-test description:
Test 1 - test's if an incorrect option yields an exit status of 1
Test 2 - test's if a correct input and input yields an exit status of 0
Test 3 - test's if the --catch option yields an exit status of 4
Test 4 - test's if a read-only input file option yields an exit status of 2
Test 5 - test's if a non-existant input file yields an exit status of 2