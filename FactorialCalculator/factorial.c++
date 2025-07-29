#include <iostream>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number = 5;
    int result = factorial(number);
    std::cout << "Factorial of " << number << " is " << result << std::endl;
    return 0;
}