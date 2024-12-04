#include <iostream>
#include <string>

/* === Inheritance Notes ===
- If you don’t specify virtual for the function that is in both parent and child classes, 
    the child class version shadows or hides the parent class version.
    - this will give static binding insread of dynamic binding
- Static binding: binding of which method is done at compile time, early binding
    - function overloading
    - inheritance is not a requirement for overloading
- Dynamic binding: binding of which is done at run time, late binding
    - function overriding
    - inheritance is a requirement for overriding
    - name function shared in parent and child classes as virtual
- override keyword in derived classes ensures that the function is intended to be overriden
- if you dont use virtual keyword then child class method redefines the function (it hides or shadows it)
- Polymorphism only works through pointers and references
    - invoking from actual object only gives static binding
- final keywrord at end of prototype is used ot prevenet a virtual function from being overriden
- classes can also be declared final in which they cannot be used as a parent class
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

    // Virtual function for dynamic binding
    virtual void speak() const {
        std::cout << name << " makes a sound." << std::endl;
    }

    // Non-virtual function for static binding
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

    // Copy constructor
    Dog(const Dog& other) : Animal(other), breed(other.breed) {
        std::cout << "Dog copy constructor called for " << name << std::endl;
    }

    // Override speak (dynamic binding)
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

    // Non-virtual function to demonstrate static binding
    void eat() const {
        std::cout << name << " is eating dog food." << std::endl;
    }
};

int main() {
    // Example of inheritance and overriding
    Animal* animal = new Dog("Buddy", "Golden Retriever");
    animal->speak(); // Calls overridden speak in Dog (dynamic binding)
    animal->eat();   // Calls Animal's eat (static binding)

    // Example of copy constructor
    Dog dog1("Max", "Bulldog");
    Dog dog2 = dog1; // Calls Dog's copy constructor

    // Example of overloading
    dog2.displayBreed();
    dog2.displayBreed("Alice");

    // Example of static vs dynamic binding
    Dog* specificDog = new Dog("Charlie", "Beagle");
    specificDog->speak(); // Calls Dog's speak (dynamic binding)
    specificDog->eat();   // Calls Dog's eat (static binding)

    delete animal;
    delete specificDog;
    return 0;
}
