#include <iostream>
#include <string.h>
#include <vector>
#include <dirent.h>

void GetFiles(const char* path, std::vector<std::string>* files) {
    DIR* directory = opendir(path);
    if (directory != nullptr) {
        struct dirent *entry = readdir(directory);
        while (entry){
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                files->push_back(entry->d_name);
            }
            entry = readdir(directory);
        }
        closedir(directory);
    }
}

int main(int argc, char const *argv[]) {
    const char* path = "txt";
    std::vector<std::string> files;
    GetFiles(path, &files);
    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
    return 0;
}
