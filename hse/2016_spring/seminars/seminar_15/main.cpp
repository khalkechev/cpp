#include "search_engine.h"
#include <iostream>

void PrintSearchResults(const std::vector<std::string>& documents) {
    std::cout << "==========================\n";
    for (const auto& document : documents) {
        std::cout << document << std::endl;
    }
    std::cout << "==========================\n";
}

void PrintUsageAndExit(int argc, char const *argv[]) {
    std::cerr << "Usage: " << argv[0] << " documents_file_name inverted_index_file_name\n";
    std::cerr << "documents_file_name: file name with documents names\n";
    std::cerr << "inverted_index_file_name: file name with inverted index\n";
    exit(1);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        PrintUsageAndExit(argc, argv);
    }
    NHSE::TSearchEngine searchEngine(argv[1], argv[2]);
    std::cerr << "Search engine is loaded\n";
    std::string query;
    while (query != "exit") {
        std::cout << "Query: ";
        std::getline(std::cin, query);
        std::vector<std::string> documents = searchEngine.Search(query);
        PrintSearchResults(documents);
    }

    return 0;
}
