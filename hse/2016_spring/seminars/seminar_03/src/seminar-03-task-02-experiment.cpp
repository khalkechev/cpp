#include <iostream>
#include <ctime>

int min_old(int value) {
    if (value == 0) {
        return 0;
    }
    int result = 9;
    while (value > 0) {
        if (value % 10 < result) {
            result = value % 10;
        }
        value = value / 10;
    }
    return result;
}

int min_new(int value) {
    if (value == 0) {
        return 0;
    }
    int result = 9;
    while (value > 0) {
        int remainder = value % 10;
        if (remainder < result) {
            result = remainder;
        }
        value = value / 10;   
    }
    return result;
}

int main(int argc, char const *argv[]) {
    clock_t start_old = clock();
    for (size_t value = 0; value < 100000000; ++value) {
        min_old(value);
    }
    clock_t time_old = clock() - start_old;
    float seconds_old = static_cast<float>(time_old) / CLOCKS_PER_SEC;
    std::cout << "seconds_old = [" << seconds_old << "]\n";

    clock_t start_new = clock();
    for (size_t value = 0; value < 100000000; ++value) {
        min_new(value);
    }
    clock_t time_new = clock() - start_new;
    float seconds_new = static_cast<float>(time_new) / CLOCKS_PER_SEC;
    std::cout << "seconds_new = [" << seconds_new << "]\n";

    return 0;
}
