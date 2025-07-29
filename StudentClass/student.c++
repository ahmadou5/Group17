#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;
    float gpa;

public:
    // Constructor
    Student(const std::string& name, int id, float gpa) 
        : name(name), id(id), gpa(gpa) {}
    
    // Getter methods
    std::string getName() const { return name; }
    int getId() const { return id; }
    float getGPA() const { return gpa; }
    
    // Setter methods
    void setGPA(float newGPA) {
        gpa = newGPA;
        std::cout << "GPA updated to " << newGPA << " for " << name << std::endl;
    }
    
    // Method to display student information
    void display() const {
        std::cout << "Student: " << name << " (ID: " << id 
                  << ", GPA: " << gpa << ")" << std::endl;
    }
    
    // Method to check if student is honor student
    bool isHonorStudent() const {
        return gpa >= 3.5;
    }
};

int main() {
    Student student1("Alice Johnson", 12345, 3.8);
    
    student1.display();
    
    if (student1.isHonorStudent()) {
        std::cout << student1.getName() << " is an honor student!" << std::endl;
    }
    
    student1.setGPA(3.9);
    student1.display();
    
    return 0;
}