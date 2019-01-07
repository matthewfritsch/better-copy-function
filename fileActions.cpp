//
// Created by matthew on 1/3/19.
//


#include "fileActions.hpp"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>


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
//    if (is_dir(path)) {
//        std::cout << "This directory exists!" << std::endl;
//        return true;
//    } else if (is_file(path)) {
//        std::cout << "This file exists!" << std::endl;
//        return true;
//    } else
//        std::cout << "Problem with " << path << std::endl;
//    return false;
    return is_dir(path) || is_file(path);
}

bool fileActions::writeFile() {
    return false;
}

bool fileActions::readFile() {
    return false;
}

char *fileActions::findHomedir(char *path) {
    char *homedir;
    if ((homedir = getenv("HOME")) == nullptr) {
        std::cout << "b" << std::endl;
        homedir = getpwuid(getuid())->pw_dir;
    }
    if (path[0] == '~') {

        std::string paths(path);
        std::string homedirs(homedir);
        std::string total = homedirs + paths.substr(1);
        //std::cout << "This is the total: " << &total[0] << std::endl;
        char *ret = new char[total.size() + 1];
        std::copy(total.begin(), total.end(), ret);
        ret[total.size()] = '\0';
        //std::cout << "Ret is "<< ret << std::endl;
        return ret;
    }
    //std::cout << "This is the path: " << path << std::endl;
    return path;
}

void fileActions::read_directory(const std::string name, std::vector<std::string> &v) {
    DIR *dirp = opendir(name.c_str());
    std::vector<std::string> newVec;
    struct dirent *dp;
    while ((dp = readdir(dirp)) != nullptr) {
        newVec.push_back(dp->d_name);
    }
    closedir(dirp);
    for (int x = newVec.size() - 1; x >= 0; x--) {
        if (newVec[x] == ".." || newVec[x] == ".") {
            newVec.erase(newVec.begin() + x);
        } else {

            newVec[x] = START + "/" + newVec[x];
            //std::cout << newVec[x] << std::endl;
        }
    }
    for (std::string s:newVec) {
        v.push_back(s);
    }
    newVec.clear();
}

bool fileActions::checkAndCopy(int argc, char *args[]) {
    if (check(argc, args)) { //provided we have a starting place, ending place, and all variables are taken care of...
        if (is_dir(START.c_str())) {
            mkdir(FINISH.c_str(), 0777);
            if (recursive) {
                read_directory(START, toWrite);
                for (int x = 0; x < toWrite.size(); x++) {
                    if (is_dir((toWrite[x]).c_str())) {
                        //std::cout << START + "/" + toWrite[x] << " is a dir" << std::endl;
                        read_directory(toWrite[x], toWrite);
                    } //else if (is_file((START + "/" + toWrite[x]).c_str()))
                    //std::cout << START + "/" + toWrite[x] << " is a file" << std::endl;
                }
                for (std::string str : toWrite) {
                    if (is_dir(str.c_str())) {
                        std::cout << str << " is a directory" << std::endl;
                    } else if (is_file(str.c_str())) {
                        std::cout << str << " is a file" << std::endl;
                    }
                }
            }
        }
    } else {
        showHelp();
        return false;
    }
    return true;
}

bool fileActions::check(int argc, char *args[]) { //sort out the required booleans
    for (int x = argc - 1; x > 0; x--) {
        if (x == argc - 1)//{
            FINISH = findHomedir(args[x]);
            //std::cout << "Finish is now " << findHomedir(args[x]) << std::endl;}
        else if (x == argc - 2)//{
            START = findHomedir(args[x]);
            //std::cout << "Start is now " << findHomedir(args[x]) << std::endl;}
        else {
            //std::cout << args[x] << std::endl;
            if (strcmp(args[x], "-v") == 0) {
                verbose = true;
            } else if (strcmp(args[x], "-c") == 0) {
                showCompletionBar = false;
            } else if (strcmp(args[x], "-r") == 0) {
                recursive = true;
            } else {
                std::cerr << "Problems!" << std::endl;
                return false;
            }
        }
    }

    return is_exist(START.c_str());
}