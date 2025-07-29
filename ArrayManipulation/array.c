#include <stdio.h>

int main() {
    int numbers[] = {10, 25, 8, 42, 15, 33, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Calculate sum
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    
    // Calculate average
    double average = (double)sum / size;
    
    // Find maximum
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max);
    
    return 0;
}