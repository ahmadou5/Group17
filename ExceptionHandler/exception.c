#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int divide(int a, int b, int* result) {
    if (b == 0) {
        return -1; // Error code for division by zero
    }
    *result = a / b;
    return 0; // Success
}

int openAndReadFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s': %s\n", filename, strerror(errno));
        return -1;
    }
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(file);
    return 0;
}

int main() {
    int result;
    
    // Division example with error handling
    printf("Division Examples:\n");
    if (divide(10, 2, &result) == 0) {
        printf("10 / 2 = %d\n", result);
    } else {
        printf("Error: Division by zero!\n");
    }
    
    if (divide(10, 0, &result) == 0) {
        printf("10 / 0 = %d\n", result);
    } else {
        printf("Error: Division by zero!\n");
    }
    
    // File operation with error handling
    printf("\nFile Operation Example:\n");
    if (openAndReadFile("nonexistent.txt") != 0) {
        printf("Failed to read file.\n");
    }
    
    return 0;
}