# Base class
class Animal:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def make_sound(self):
        print("The animal makes a sound")
    
    def display(self):
        print(f"Animal: {self.name}, Age: {self.age}")
    
    def __str__(self):
        return f"Animal(name='{self.name}', age={self.age})"

# Derived class
class Dog(Animal):
    def __init__(self, name, age, breed):
        super().__init__(name, age)  # Call parent constructor
        self.breed = breed
    
    def make_sound(self):
        print("Woof! Woof!")
    
    def display(self):
        print(f"Dog: {self.name}, Age: {self.age}, Breed: {self.breed}")
    
    # Dog-specific method
    def wag_tail(self):
        print("The dog is wagging its tail!")
    
    def __str__(self):
        return f"Dog(name='{self.name}', age={self.age}, breed='{self.breed}')"

def main():
    animal = Animal("Generic Animal", 5)
    dog = Dog("Buddy", 3, "Golden Retriever")
    
    print("Animal operations:")
    animal.display()
    animal.make_sound()
    
    print("\nDog operations:")
    dog.display()
    dog.make_sound()
    dog.wag_tail()
    
    # Polymorphism demonstration
    print("\nPolymorphism demonstration:")
    animals = [
        Animal("Generic Animal 2", 7),
        Dog("Max", 2, "Labrador")
    ]
    
    for animal_ref in animals:
        animal_ref.display()
        animal_ref.make_sound()
        print()
    
    # Type checking and method access
    print("Type checking example:")
    for animal_ref in animals:
        if isinstance(animal_ref, Dog):
            animal_ref.wag_tail()
        print(f"Type: {type(animal_ref).__name__}")
    
    # Demonstrating method resolution order
    print(f"\nDog MRO: {Dog.__mro__}")

if __name__ == "__main__":
    main()