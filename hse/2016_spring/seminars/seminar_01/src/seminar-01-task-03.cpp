#include <iostream>
#include <string>

static bool IsPalindrom(const std::string& string) {
    size_t length = string.length();
    for (size_t index = 0; index < length / 2; ++index) {
        if (string[index] != string[length - index - 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    std::string string;
    while (getline(std::cin, string)) {
        if (IsPalindrom(string)) {
            std::cout << "Palindrom.\n";
        } else {
            std::cout << "Not a palindrom.\n";
        }
    }
    return 0;
}
