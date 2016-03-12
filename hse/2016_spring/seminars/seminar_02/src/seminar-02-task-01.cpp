#include <iostream>

int main(int argc, char const *argv[]) {
    if (sizeof(char) <= sizeof(int) && sizeof(int) <= sizeof(double)) {
        std::cout << "Yes, it is.\n";
    } else {
        std::cout << "No, it is not.\n";
    }
    return 0;
}
