//
// Created by matthew on 1/3/19.
//

#ifndef POINTERTEST_FILEACTIONS_HPP
#define POINTERTEST_FILEACTIONS_HPP


class fileActions {
private:
    struct File {
        std::string path;
        long long int sizeInBytes;
        bool isDirectory;

        File(std::string newPath, long long int newSize, bool isDir) {
            path = newPath;
            sizeInBytes = newSize;
            isDirectory = isDir;
        }
    };

    bool verbose = false;
    bool recursive = false;
    bool showCompletionBar = true;

public:
    fileActions();

    ~fileActions();

    void showHelp();

    bool checkAndCopy(char *args[]);

    bool is_file(const char *path);

    bool is_dir(const char *path);

    char *findHomedir(char *path);

    void read_directory(const std::string name, std::vector<std::string> &v);

    bool writeFile();

    bool readFile();


};


#endif //POINTERTEST_FILEACTIONS_HPP
