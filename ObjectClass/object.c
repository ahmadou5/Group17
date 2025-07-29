#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

// Constructor-like function
Student* createStudent(const char* name, int id, float gpa) {
    Student* student = (Student*)malloc(sizeof(Student));
    strcpy(student->name, name);
    student->id = id;
    student->gpa = gpa;
    return student;
}

// Method-like functions
void displayStudent(const Student* student) {
    printf("Student: %s (ID: %d, GPA: %.2f)\n", 
           student->name, student->id, student->gpa);
}

void updateGPA(Student* student, float newGPA) {
    student->gpa = newGPA;
    printf("GPA updated to %.2f for %s\n", newGPA, student->name);
}

int isHonorStudent(const Student* student) {
    return student->gpa >= 3.5;
}

void destroyStudent(Student* student) {
    free(student);
}

int main() {
    Student* student1 = createStudent("Alice Johnson", 12345, 3.8);
    
    displayStudent(student1);
    
    if (isHonorStudent(student1)) {
        printf("%s is an honor student!\n", student1->name);
    }
    
    updateGPA(student1, 3.9);
    displayStudent(student1);
    
    destroyStudent(student1);
    return 0;
}