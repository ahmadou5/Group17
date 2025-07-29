#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Base "class" - Animal
typedef struct {
    char name[50];
    int age;
    void (*makeSound)(void);
    void (*display)(void*);
} Animal;

// Derived "class" - Dog
typedef struct {
    Animal base;  // Inheritance simulation
    char breed[50];
    void (*wagTail)(void);
} Dog;

// Animal methods
void animalMakeSound() {
    printf("The animal makes a sound\n");
}

void animalDisplay(void* self) {
    Animal* animal = (Animal*)self;
    printf("Animal: %s, Age: %d\n", animal->name, animal->age);
}

// Dog methods
void dogMakeSound() {
    printf("Woof! Woof!\n");
}

void dogDisplay(void* self) {
    Dog* dog = (Dog*)self;
    printf("Dog: %s, Age: %d, Breed: %s\n", 
           dog->base.name, dog->base.age, dog->breed);
}

void dogWagTail() {
    printf("The dog is wagging its tail!\n");
}

// Constructor functions
Animal* createAnimal(const char* name, int age) {
    Animal* animal = (Animal*)malloc(sizeof(Animal));
    strcpy(animal->name, name);
    animal->age = age;
    animal->makeSound = animalMakeSound;
    animal->display = animalDisplay;
    return animal;
}

Dog* createDog(const char* name, int age, const char* breed) {
    Dog* dog = (Dog*)malloc(sizeof(Dog));
    strcpy(dog->base.name, name);
    dog->base.age = age;
    strcpy(dog->breed, breed);
    
    // Override methods (polymorphism simulation)
    dog->base.makeSound = dogMakeSound;
    dog->base.display = dogDisplay;
    dog->wagTail = dogWagTail;
    
    return dog;
}

int main() {
    Animal* animal = createAnimal("Generic Animal", 5);
    Dog* dog = createDog("Buddy", 3, "Golden Retriever");
    
    printf("Animal operations:\n");
    animal->display(animal);
    animal->makeSound();
    
    printf("\nDog operations:\n");
    dog->base.display(dog);
    dog->base.makeSound();
    dog->wagTail();
    
    // Polymorphism demonstration
    printf("\nPolymorphism demonstration:\n");
    Animal* animals[] = {animal, (Animal*)dog};
    for (int i = 0; i < 2; i++) {
        animals[i]->display(animals[i]);
        animals[i]->makeSound();
        printf("\n");
    }
    
    free(animal);
    free(dog);
    return 0;
}