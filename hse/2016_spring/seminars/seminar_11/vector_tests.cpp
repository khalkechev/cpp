#include <ctime>
#include <iostream>
#include <vector>

void test1() {
    std::vector<size_t> v;
    for (size_t i = 0; i < 100000000; ++i) {
        v.push_back(i);
    }
}
void test2() {
    std::vector<size_t> v;
    v.reserve(100000000);
    for (size_t i = 0; i < 100000000; ++i) {
        v.push_back(i);
    }
}
void test3() {
    std::vector<size_t> v;
    v.resize(100000000);
    for (size_t i = 0; i < 100000000; ++i) {
        v[i] = i;
    }
}
int main(int argc, char const *argv[]) {

    clock_t startTime = clock();
    test3();
    double test3Time = double(clock() - startTime) / CLOCKS_PER_SEC;
    std::cout << "Test 3 time: " << test3Time << std::endl;

    startTime = clock();
    test2();
    double test2Time = double(clock() - startTime) / CLOCKS_PER_SEC;
    std::cout << "Test 2 time: " << test2Time << std::endl;

    startTime = clock();
    test1();
    double test1Time = double(clock() - startTime) / CLOCKS_PER_SEC;
    std::cout << "Test 1 time: " << test1Time << std::endl;

    return 0;
}
