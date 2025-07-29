#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Division by zero error";
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

int main() {
    // Division example with exception handling
    std::cout << "Division Examples:" << std::endl;
    
    try {
        double result = divide(10.0, 2.0);
        std::cout << "10 / 2 = " << result << std::endl;
        
        result = divide(10.0, 0.0); // This will throw an exception
        std::cout << "10 / 0 = " << result << std::endl;
    }
    catch (const DivisionByZeroException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    
    // File operation with exception handling
    std::cout << "\nFile Operation Example:" << std::endl;
    try {
        readFile("nonexistent.txt");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "File error: " << e.what() << std::endl;
    }
    
    return 0;
}