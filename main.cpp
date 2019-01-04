#include <iostream>
#include "fileActions.hpp"

int main(int argc, char *argv[]) {
    fileActions fa;
    if (argc < 3) {//if too few arguments
        fa.showHelp();//show help plan, and all possible options
        return 0;
    }
    else //otherwise
        return fa.checkAndCopy(argc, argv);//copy bytes from A to B, provided all prerequisites are met.
}
