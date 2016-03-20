#include <iostream>

static void GetMinAndMaxDigits(int number, int* min, int* max) {
    if (number == 0) {
        *min = *max = 0;
        return;
    }
    if (number < 0) {
        number *= -1;
    }
    *min = 9;
    *max = 0;
    while (number != 0) {
        int digit = number % 10;
        *min = std::min(*min, digit);
        *max = std::max(*max, digit);
        number /= 10;
    }
}

int main(int argc, char const *argv[]) {
    int number = -223456;
    int min, max;
    GetMinAndMaxDigits(number, &min, &max);
    std::cout << "number = " << number << ", min = " << min << ", max = " << max << std::endl;
    return 0;
}
