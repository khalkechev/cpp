#include <iostream>
#include <string>

static void ReversePrint(const std::string& string) {
    for (int i = string.length() - 1; i >= 0; --i) {
        std::cout << string[i];
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    std::string string;
    std::cin >> string;
    ReversePrint(string);
    return 0;
}
