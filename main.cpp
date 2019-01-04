#include <iostream>
#include "fileActions.hpp"

int main(int argc, char *argv[]) {
    fileActions fa;
    if (argc < 3)//if too few arguments
        fa.showHelp();//show help plan, and all possible options
    else //otherwise
    if (argc == 3)//if three arguments
        fa.checkAndCopy(argc, argv);//copy bytes from A to B
    else//if more
        fa.betterCheckAndCopy(argc, argv);//change boolean values for recursive, verbose, and completion bar.
}
