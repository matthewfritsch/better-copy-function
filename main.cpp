#include <iostream>
#include "fileActions.hpp"

int main(int argc, char *argv[]) {
    fileActions fa;
    if (argc < 3)//if too few arguments
        fa.showHelp();//show help plan, and all possible options
    else //otherwise
    if (argc == 3)//if three arguments
        fa.checkAndCopy(argv);//copy bytes from A to B
    else//if more
        fa.betterCheckAndCopy(argv);//change boolean values for recursive, verbose, and completion bar.

//    if (argc < 3) {
//        std::cout << "Too few arguments given" << std::endl;
//        showHelp();
//    } else if (argc == 3) {
//        if (is_dir(findHomedir(argv[1]))) {
//            std::cout << findHomedir(argv[1]) << std::endl;
//            std::vector<std::string> vec;
//            std::string s(findHomedir(argv[1]));
//            read_directory(s, vec);
//            for(std::string x:vec){
//                std::cout << findHomedir(argv[1]) << '/' << x << std::endl;
//            }
//            return 0;
//        } else if (is_file(findHomedir(argv[1]))) {
//            std::cout << "This is a file!" << std::endl;
//            std::cout << findHomedir(argv[1]) << std::endl;
//        } else {
//            std::cout << "File does not exist!" << std::endl;
//            std::cout << findHomedir(argv[1]) << std::endl;
//            return 1;
//        }
//        std::ifstream data;
//        data.open(argv[1]);
//        if (data.bad()) {
//            std::cout << "File " << argv[1] << " not found." << std::endl;
//            data.close();
//            return 1;
//        }
//        std::ofstream out;
//        out.open((argv[2]));
//    } else {
//        std::cout << argc - 1 << " arguments provided. These include:" << std::endl;
//        for (int x = 1; x < argc; x++) {
//            std::cout << argv[x] << std::endl;
//        }
//    }
}
