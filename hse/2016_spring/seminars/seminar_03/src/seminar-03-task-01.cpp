#include <iostream>

static size_t CalcEvenDigitsCount(int number) {
    if (number == 0) {
        return 1;
    }
    size_t result = 0;
    while (number != 0) {
        int digit = number % 10;
        if (digit % 2 == 0) {
            ++result;
        }
        number /= 10;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int number = -1234567890;
    std::cout << "CalcEvenDigitsCount(" << number << ") = "
              << CalcEvenDigitsCount(number) << std::endl;
    return 0;
}
