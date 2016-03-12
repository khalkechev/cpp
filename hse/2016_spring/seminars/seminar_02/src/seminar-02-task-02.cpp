#include <iostream>

bool isPrime(unsigned int value) {
    if (value == 1) {
        return false;
    }
    for (int i = 2; i < value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;

}
int main(int argc, char const *argv[]) {
    
    if (argc < 3) {
        std::cout << "Bad input. Input numbers, please.\n";
        return 1;
    }

    unsigned int firstNumber = atoi(argv[1]);
    unsigned int secondNumber = atoi(argv[2]);

    for (int number = firstNumber; number < secondNumber; ++number) {
        if (isPrime(number)) {
            std::cout << number << std::endl;
            return 0;
        }
    }
    std::cout << "Not found prime numbers.\n";
    return 0;
}
