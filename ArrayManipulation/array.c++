#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers = {10, 25, 8, 42, 15, 33, 7};
    
    // Calculate sum
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    
    // Calculate average
    double average = static_cast<double>(sum) / numbers.size();
    
    // Find maximum
    int max = *std::max_element(numbers.begin(), numbers.end());
    
    std::cout << "Array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Maximum: " << max << std::endl;
    
    return 0;
}