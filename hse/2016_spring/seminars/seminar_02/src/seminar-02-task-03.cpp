#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 1;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}
