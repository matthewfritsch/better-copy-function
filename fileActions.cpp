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

}

fileActions::~fileActions() {

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
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}