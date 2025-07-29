#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Base class
class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age) : name(name), age(age) {}
    
    // Virtual destructor for proper cleanup
    virtual ~Animal() = default;
    
    // Virtual methods for polymorphism
    virtual void makeSound() const {
        std::cout << "The animal makes a sound" << std::endl;
    }
    
    virtual void display() const {
        std::cout << "Animal: " << name << ", Age: " << age << std::endl;
    }
    
    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

// Derived class
class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed) 
        : Animal(name, age), breed(breed) {}
    
    // Override base class methods
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
    
    void display() const override {
        std::cout << "Dog: " << name << ", Age: " << age 
                  << ", Breed: " << breed << std::endl;
    }
    
    // Dog-specific method
    void wagTail() const {
        std::cout << "The dog is wagging its tail!" << std::endl;
    }
    
    std::string getBreed() const { return breed; }
};

int main() {
    Animal animal("Generic Animal", 5);
    Dog dog("Buddy", 3, "Golden Retriever");
    
    std::cout << "Animal operations:" << std::endl;
    animal.display();
    animal.makeSound();
    
    std::cout << "\nDog operations:" << std::endl;
    dog.display();
    dog.makeSound();
    dog.wagTail();
    
    // Polymorphism demonstration
    std::cout << "\nPolymorphism demonstration:" << std::endl;
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Animal>("Generic Animal 2", 7));
    animals.push_back(std::make_unique<Dog>("Max", 2, "Labrador"));
    
    for (const auto& animalPtr : animals) {
        animalPtr->display();
        animalPtr->makeSound();
        std::cout << std::endl;
    }
    
    return 0;
}