#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[] = "Hello, World!\nThis is a file write operation in C.\nLine 3 of the file.";
    char buffer[256];
    
    // Write to file
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written to file successfully.\n");
    
    // Read from file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    printf("\nReading from file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(file);
    
    // Clean up
    remove("example.txt");
    
    return 0;
}