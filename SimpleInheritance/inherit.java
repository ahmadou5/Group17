// Base class
class Animal {
    protected String name;
    protected int age;
    
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    public void makeSound() {
        System.out.println("The animal makes a sound");
    }
    
    public void display() {
        System.out.println("Animal: " + name + ", Age: " + age);
    }
    
    // Getters
    public String getName() { return name; }
    public int getAge() { return age; }
}

// Derived class
class Dog extends Animal {
    private String breed;
    
    public Dog(String name, int age, String breed) {
        super(name, age);  // Call parent constructor
        this.breed = breed;
    }
    
    @Override
    public void makeSound() {
        System.out.println("Woof! Woof!");
    }
    
    @Override
    public void display() {
        System.out.println("Dog: " + name + ", Age: " + age + ", Breed: " + breed);
    }
    
    // Dog-specific method
    public void wagTail() {
        System.out.println("The dog is wagging its tail!");
    }
    
    public String getBreed() { return breed; }
}

public class InheritanceExample {
    public static void main(String[] args) {
        Animal animal = new Animal("Generic Animal", 5);
        Dog dog = new Dog("Buddy", 3, "Golden Retriever");
        
        System.out.println("Animal operations:");
        animal.display();
        animal.makeSound();
        
        System.out.println("\nDog operations:");
        dog.display();
        dog.makeSound();
        dog.wagTail();
        
        // Polymorphism demonstration
        System.out.println("\nPolymorphism demonstration:");
        Animal[] animals = {
            new Animal("Generic Animal 2", 7),
            new Dog("Max", 2, "Labrador")
        };
        
        for (Animal animalRef : animals) {
            animalRef.display();
            animalRef.makeSound();
            System.out.println();
        }
        
        // Downcasting example
        System.out.println("Downcasting example:");
        for (Animal animalRef : animals) {
            if (animalRef instanceof Dog) {
                Dog dogRef = (Dog) animalRef;
                dogRef.wagTail();
            }
        }
    }
}