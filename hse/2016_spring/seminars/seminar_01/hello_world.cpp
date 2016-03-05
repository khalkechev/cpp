#include <iostream>

int main(int argc, char const *argv[]) {
    std::string string;
    std::cout << "What is your name?\n";
    std::getline(std::cin, string);
    std::cout << "Hello, " << string << "!\n";
    return 0;
}
