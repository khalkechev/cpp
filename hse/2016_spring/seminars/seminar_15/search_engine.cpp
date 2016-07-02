#include "search_engine.h"
#include <algorithm>
#include <fstream>

namespace NHSE {

///////////////////////////////////////////////////////////////////////////////////////////////////

TSearchEngine::TSearchEngine(const std::string& documentsFileName,
                             const std::string& invertedIndexFileName)
{
    LoadDocuments(documentsFileName);
    LoadInvertedIndex(invertedIndexFileName);
}

void TSearchEngine::LoadDocuments(const std::string& documentsFileName) {
    std::ifstream documentsFile(documentsFileName);
    std::string line;
    while (std::getline(documentsFile, line)) {
        Documents.push_back(line);
    }
}

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

void TSearchEngine::LoadInvertedIndex(const std::string& invertedIndexFileName) {
    std::ifstream invertedIndexFile(invertedIndexFileName);
    std::string line;
    while (std::getline(invertedIndexFile, line)) {
        std::vector<std::string> fields;
        Split(line, '\t', &fields);
        const std::string& word = fields[0];
        for (size_t i = 1; i < fields.size(); ++i) {
            int docNumber = atoi(fields[i].c_str());
            InvertedIndex[word].insert(docNumber);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> TSearchEngine::Search(const std::string& query) const {
    std::vector<std::string> result;
    if (query.empty()) {
        return result;
    }
    std::vector<std::string> words;
    Split(query, ' ', &words);
    auto it = InvertedIndex.find(words[0]);
    if (it == InvertedIndex.end()) {
        return result;
    }
    std::set<int> resultDocumentsNumbers = it->second;
    for (size_t i = 1; i < words.size(); ++i) {
        const std::string& word = words[i];
        auto it = InvertedIndex.find(word);
        if (it == InvertedIndex.end()) {
            result.clear();
            return result;
        }
        std::set<int> intersection;
        std::set_intersection(resultDocumentsNumbers.begin(),
                              resultDocumentsNumbers.end(),
                              it->second.begin(),
                              it->second.end(),
                              std::inserter(intersection, intersection.begin()));
        resultDocumentsNumbers = intersection;
    }

    result.reserve(resultDocumentsNumbers.size());
    for (int documentNumber : resultDocumentsNumbers) {
        result.push_back(Documents[documentNumber]);
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

}
