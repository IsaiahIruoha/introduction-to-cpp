#include <iostream>
#include <string>

/* === Base Class References Notes === 
- Functions that expect base class reference allow for more abstraction and not
  having to think about what object is being passed in and which function to call
*/

// Base class: Animal
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    virtual void speak() const {
        std::cout << name << " makes a sound." << std::endl;
    }

    void eat() const {
        std::cout << name << " is eating." << std::endl;
    }

    virtual ~Animal() {}
};

// Derived class: Dog
class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& n, const std::string& b) : Animal(n), breed(b) {}

    void speak() const override {
        std::cout << name << " barks!" << std::endl;
    }

    void eat() const {
        std::cout << name << " is eating dog food." << std::endl;
    }

    void displayBreed() const {
        std::cout << name << " is a " << breed << std::endl;
    }
};

int main() {
    Dog dog("Buddy", "Golden Retriever");

    // Using a base class reference
    Animal& animalRef = dog;

    // Demonstrates dynamic binding (virtual function)
    animalRef.speak(); // Calls Dog's speak due to dynamic binding

    // Demonstrates static binding (non-virtual function)
    animalRef.eat(); // Calls Animal's eat due to static binding

    return 0;
}
