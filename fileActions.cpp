//
// Created by matthew on 1/3/19.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
#include "fileActions.hpp"

fileActions::fileActions() {
    verbose = false;
    recursive = false;
    showCompletionBar = true;
}

void fileActions::showHelp() {
    std::cout << "\"ecp [OPTIONS] <SOURCE> <DEST>\"" << std::endl;
    std::cout << "  OPTIONS:" << std::endl;
    std::cout << "  -r ==== Recursively copies all files below the current directory" << std::endl;
}

bool fileActions::is_file(const char *path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool fileActions::is_dir(const char *path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

bool fileActions::is_exist(const char *path) {
    return is_dir(path) || is_file(path);
}

bool fileActions::writeFile() {

}

bool fileActions::readFile() {

}

char *fileActions::findHomedir(char *path) {
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
    //std::cout << "This is the path: " << path << std::endl;
    return path;
}

void fileActions::read_directory(const std::string name, std::vector<std::string> &v) {
    DIR *dirp = opendir(name.c_str());
    struct dirent *dp;
    while ((dp = readdir(dirp)) != nullptr) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}

bool fileActions::betterCheckAndCopy(int argc, char *args[]) {

}

bool fileActions::checkAndCopy(int argc, char *args[]) {
    if (check(argc, args)) {

    } else {
        showHelp();
        return false;
    }
}

bool fileActions::check(int argc, char *args[]) {
    for (int x = argc - 1; x >= 0; x++) {
        if (x == argc - 1)
            FINISH = args[x];
        else if (x == argc - 2)
            START = args[x];
        else {
            if (args[x] == "-v") {
                verbose = true;
            } else if (args[x] == "-c") {
                showCompletionBar = false;
            } else if (args[x] == "-r") {
                recursive = true;
            } else {
                std::cerr << "Problems!" << std::endl;
                return false;
            }
        }
    }
    return is_exist(FINISH) && is_exist(START);
}