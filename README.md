# better-copy-function
I've had some difficulty with the way that the "cp" command works on the terminal emulator of my copy of Linux. The difficulty does not lie in the actual use of the copy program, but moreso that it takes **extensive** periods of time for the command to actually perform its job. [This could be due to my system being slow, but no system should struggle to perform the copy command in 2019 with 16GB DDR4, a 6c12t CPU, and writing to & from an SSD with no background programs open] The purpose of the creation of this program is to get practice with file system basics in C++ using the POSIX library "sys" (primarily stat.h), and to get back in touch with C++ fundamentals. Ultimately the goal is to create a tool that can copy files to a new location *faster* than the "cp" command. 

As of writing this (1/3/2019), I have two years of college-level C++ experience, and zero experience writing terminal programs for UNIX systems, using POSIX libraries, or directly really writing a C++ project on/for any OS but Windows 10 (wrote a couple Java programs on MacOS).

**All help is appreciated, please throw me a pull request :)**



### Goals:

[x] Change any argument beginning with \'\~\' to the user's home directory (e.g \"~/Desktop/Anthem.flac\" becomes \"/home/matthew/Desktop/Anthem.flac\")

[] Have a "command helper" print out to show the user the correct format, all options, and other necessary info when the command is run with the --help option, or if there are less than 3 arguments (one for the program execution, one for the file to be copied, and one more for the location in which it is copied to)

[x] Detect if a path points to a file, a directory, or something that cannot be copied.

TODO Add more here
