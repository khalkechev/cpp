#include <iostream>

static long long int Factorial(unsigned int number) {
    long long int result = 1;
    if (number == 0) {
        return result;
    }
    for (size_t i = 1; i < number; ++i) {
        result *= i;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    std::cout << "Factorial(0) = "  << Factorial(0) << std::endl;
    std::cout << "Factorial(3) = "  << Factorial(3) << std::endl; 
    std::cout << "Factorial(10) = " << Factorial(10) << std::endl;
    return 0;
}
