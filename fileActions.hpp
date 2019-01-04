//
// Created by matthew on 1/3/19.
//

#ifndef POINTERTEST_FILEACTIONS_HPP
#define POINTERTEST_FILEACTIONS_HPP


class fileActions {
private:

    struct File {
        std::string *path;
        long long int *sizeInBytes;
        bool *isDirectory;
        File(std::string newPath, long long int newSize, bool isDir) {
            *path = newPath;
            *sizeInBytes = newSize;
            *isDirectory = isDir;
        }

        void cleanVar() {
            delete (path);
            delete (sizeInBytes);
            delete (isDirectory);
        }
    };

    char *START;
    char *FINISH;

    bool verbose;
    bool recursive;
    bool showCompletionBar;

    bool is_file(const char *path);

    bool is_dir(const char *path);

    char *findHomedir(char *path);

    void read_directory(const std::string name, std::vector<std::string> &v);

    bool writeFile();

    bool readFile();

    bool is_exist(const char *);

    bool check(int argc, char *args[]);
public:
    fileActions();
    void showHelp();

    bool checkAndCopy(int argc, char *args[]);

    bool betterCheckAndCopy(int argc, char *args[]);
};


#endif //POINTERTEST_FILEACTIONS_HPP
