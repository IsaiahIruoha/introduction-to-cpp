#include <iostream>
#include <string>

/* === Inheritance Notes ===
- powerful thing about inheritance is that derived class can directly invoke base class methods
*/

// Base class: Animal
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    // Copy constructor
    Animal(const Animal& other) : name(other.name) {
        std::cout << "Animal copy constructor called for " << name << std::endl;
    }

    virtual void speak() const {
        std::cout << name << " makes a sound." << std::endl;
    }

    virtual ~Animal() {}
};

// Derived class: Dog
class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& n, const std::string& b) : Animal(n), breed(b) {}

    // Copy constructor
    Dog(const Dog& other) : Animal(other), breed(other.breed) {
        std::cout << "Dog copy constructor called for " << name << std::endl;
    }

    // Override speak
    void speak() const override {
        std::cout << name << " barks!" << std::endl;
    }

    // Overloaded function
    void displayBreed() const {
        std::cout << name << " is a " << breed << std::endl;
    }

    void displayBreed(const std::string& owner) const {
        std::cout << owner << " owns a " << breed << " named " << name << std::endl;
    }
};

int main() {
    // Example of inheritance and overriding
    Animal* animal = new Dog("Buddy", "Golden Retriever");
    animal->speak(); // Calls overridden speak in Dog

    // Example of copy constructor
    Dog dog1("Max", "Bulldog");
    Dog dog2 = dog1; // Calls Dog's copy constructor

    // Example of overloading
    dog2.displayBreed();
    dog2.displayBreed("Alice");

    delete animal;
    return 0;
}