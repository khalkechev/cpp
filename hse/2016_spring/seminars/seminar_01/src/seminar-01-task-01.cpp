#include <iostream>

static long int SumOfArithmeticSeries(int number) {
    return number * (number + 1) / 2;
}

int main(int argc, char const *argv[]) {
    int number;
    while (std::cin >> number) {
        std::cout << SumOfArithmeticSeries(number) << std::endl;
    }
    return 0;
}
