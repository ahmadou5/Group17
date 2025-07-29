#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.txt";
    std::string data = "Hello, World!\nThis is a file write operation in C++.\nLine 3 of the file.";
    
    // Write to file
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }
    
    outFile << data;
    outFile.close();
    std::cout << "Data written to file successfully." << std::endl;
    
    // Read from file
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }
    
    std::cout << "\nReading from file:" << std::endl;
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    
    inFile.close();
    
    // Clean up
    std::remove(filename.c_str());
    
    return 0;
}