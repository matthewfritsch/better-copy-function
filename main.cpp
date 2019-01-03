#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>

void showHelp();

bool is_file(const char *path);

bool is_dir(const char *path);

char *findHomedir(char *path);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Too few arguments given" << std::endl;
        showHelp();
    } else if (argc == 3) {
        if (is_dir(findHomedir(argv[1]))) {
            std::cout << findHomedir(argv[1]) << std::endl;
            return 0;
        } else if (is_file(findHomedir(argv[1]))) {
            std::cout << "This is a file!" << std::endl;
            std::cout << findHomedir(argv[1]) << std::endl;
        } else {
            std::cout << "File does not exist!" << std::endl;
            std::cout << findHomedir(argv[1]) << std::endl;
            return 1;
        }
        std::ifstream data;
        data.open(argv[1]);
        if (data.bad()) {
            std::cout << "File " << *argv[1] << " not found." << std::endl;
            data.close();
            return 1;
        }
        std::ofstream out;
        out.open((argv[2]));
    } else {
        std::cout << argc - 1 << " arguments provided. These include:" << std::endl;
        for (int x = 1; x < argc; x++) {
            std::cout << argv[x] << std::endl;
        }
    }
}

void showHelp() {
    std::cout << "\"ecp [OPTIONS] <SOURCE> <DEST>\"" << std::endl;
    std::cout << "  OPTIONS:" << std::endl;
    std::cout << "  -r ==== Recursively copies all files below the current directory" << std::endl;
}

bool is_file(const char *path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool is_dir(const char *path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

char *findHomedir(char *path) {
    char *homedir;
    if ((homedir = getenv("HOME")) == nullptr) {
        std::cout << "b" << std::endl;
        homedir = getpwuid(getuid())->pw_dir;
    }
    if (path[0] == '~') {

        std::string *paths = new std::string(path);
        std::string *homedirs = new std::string(homedir);
        std::string total = *(homedirs) + paths->substr(1);
        delete (paths);
        delete (homedirs);
        //std::cout << "This is the total: " << &total[0] << std::endl;
        char *ret = new char[total.size() + 1];
        std::copy(total.begin(), total.end(), ret);
        ret[total.size()] = '\0';
        return ret;
    }
    std::cout << "This is the path: " << path << std::endl;
    return path;
}