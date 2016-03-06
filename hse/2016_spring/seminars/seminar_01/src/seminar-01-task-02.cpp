#include <iostream>

static double CelsiusToFahrenheit(double celsiusValue) {
    return 1.8 * celsiusValue + 32;
}

int main(int argc, char const *argv[]) {
    std::cout << "Please enter a Celsius value: ";
    double celsiusValue;
    std::cin >> celsiusValue;
    double fahrenheitValue = CelsiusToFahrenheit(celsiusValue);
    std::cout << celsiusValue << " degree Celsius is "
              << fahrenheitValue << " degrees Fahrenheit.\n";
    return 0;
}
