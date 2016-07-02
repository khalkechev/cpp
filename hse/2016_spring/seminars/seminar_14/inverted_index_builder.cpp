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
                std::string fileName = path;
                fileName += "/";
                fileName += entry->d_name;
                files->push_back(fileName);
            }
            entry = readdir(directory);
        }
        closedir(directory);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static void ReadDocument(const std::string documentName,
                         int docNumber,
                         std::map<std::string, std::set<int>>* invertedIndex)
{
    std::ifstream document(documentName);
    std::string line;
    while (std::getline(document, line)) {
        std::vector<std::string> words;
        Split(line, ' ', &words);
        for (const auto& word : words) {
            (*invertedIndex)[word].insert(docNumber);
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

static void SaveDocumentsNames(const std::vector<std::string>& documents,
                               const std::string& fileName)
{
    std::ofstream file(fileName);
    for (const auto& documentName : documents) {
        file << documentName << '\n';
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static void BuildInvertedIndex(const char* path, const std::string& outPrefix) {
    std::vector<std::string> documents;
    GetFiles(path, &documents);
    std::map<std::string, std::set<int>> invertedIndex;
    for (size_t docNumber = 0; docNumber < documents.size(); ++docNumber) {
        ReadDocument(documents[docNumber], docNumber, &invertedIndex);
    }
    SaveDocumentsNames(documents, outPrefix + ".files");
    SaveInvertedIndex(invertedIndex, outPrefix + ".index");
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
    BuildInvertedIndex("documents", "out");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
