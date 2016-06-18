#include <iostream>
#include <string>
#include <vector>

#include <fstream>


void Split(const std::string& line,
           char delimiter,
           std::vector<std::string>* columns)
{
    size_t begin = 0;
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] == delimiter) {
            std::string word = line.substr(begin, i - begin);
            columns->push_back(word);
            ++i;
            begin = i;
        }
    }
    std::string word = line.substr(begin);
    columns->push_back(word);
}

void Split2(const std::string& line,
           char delimiter,
           std::vector<std::string>* columns)
{
    std::string word;
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] != delimiter) {
            word += line[i];
        } else {
            columns->push_back(word);
            word = "";
        }
    }
    columns->push_back(word);
}

int main(int argc, char const *argv[]) {

    if (argc < 4) {
        std::cout << "Args: [column number] [deimiter] [filename]\n";
        return 1;
    }

    int columnNumber = atoi(argv[1]);
    char delimiter = argv[2][0];
    std::string fileName = argv[3];

    std::ifstream inputFile(fileName);
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> columns;
        Split2(line, delimiter, &columns);
        if (columnNumber - 1 < columns.size() && columnNumber - 1 >= 0) {
            std::cout << columns[columnNumber - 1] << std::endl;
        }
    }

    return 0;
}
