#include <iostream>
#include <cmath>

int atoi(const char* str) {
    int result = 0;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; --i) {
        if (i == 0 && str[0] == '-') {
            result *= -1;
        } else {
            result += (str[i] - '0') * pow(10, len - i - 1);
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    const char* str1 = "-103";
    const char* str2 = "100500";
    const char* str3 = "9";
    std::cout << "str1 = [" << str1 << "], atoi(str1) = [" << atoi(str1) << "]\n";
    std::cout << "str2 = [" << str2 << "], atoi(str2) = [" << atoi(str2) << "]\n";
    std::cout << "str3 = [" << str3 << "], atoi(str3) = [" << atoi(str3) << "]\n";
    return 0;
}
