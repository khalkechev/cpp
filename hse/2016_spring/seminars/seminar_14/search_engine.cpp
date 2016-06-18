#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <dirent.h>

///////////////////////////////////////////////////////////////////////////////////////////////////

static void Split(const std::string& line,
                  char delimiter,
                  std::vector<std::string>* fields)
{
    size_t begin = 0;
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] == delimiter) {
            std::string word = line.substr(begin, i - begin);
            fields->push_back(word);
            ++i;
            begin = i;
        }
    }
    std::string word = line.substr(begin);
    fields->push_back(word);
}

static void GetFiles(const char* path, std::vector<std::string>* files) {
    DIR* directory = opendir(path);
    if (directory != nullptr) {
        struct dirent *entry = readdir(directory);
        while (entry) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                files->push_back(entry->d_name);
            }
            entry = readdir(directory);
        }
        closedir(directory);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static void ReadFile(const std::string fileName,
                     int fileNumber,
                     std::map<std::string, std::set<int>>* invertedIndex)
{
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> words;
        Split(line, ' ', &words);
        for (const auto& word : words) {
            (*invertedIndex)[word].insert(fileNumber);
        }
    }
}

static void SaveInvertedIndex(const std::map<std::string, std::set<int>>& invertedIndex,
                              const std::string& fileName)
{
    std::ofstream file(fileName);
    for (const auto& pair : invertedIndex) {
        const std::string& word = pair.first;
        const std::set<int>& documentsList = pair.second;
        file << word;
        for (int documentNumber : documentsList) {
            file << '\t' << documentNumber;
        }
        file << '\n';
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static void BuildInvertedIndex(const char* path, const std::string& outPrefix) {
    std::vector<std::string> files;
    GetFiles(path, &files);
    std::map<std::string, std::set<int>> invertedIndex;
    for (size_t fileNumber = 0; fileNumber < files.size(); ++fileNumber) {
        ReadFile(files[fileNumber], fileNumber, &invertedIndex);
    }
    SaveInvertedIndex(invertedIndex, outPrefix + ".index");
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
    BuildInvertedIndex("documents", "out");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
