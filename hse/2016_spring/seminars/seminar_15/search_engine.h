#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

namespace NHSE {

class TSearchEngine {
    std::vector<std::string> Documents;
    std::map<std::string, std::set<int>> InvertedIndex;
public:
    TSearchEngine(const std::string& documentsFileName, const std::string& invertedIndexFileName);
    std::vector<std::string> Search(const std::string& query) const;
private:
    void LoadDocuments(const std::string& documentsFileName);
    void LoadInvertedIndex(const std::string& invertedIndexFileName);
};

}
