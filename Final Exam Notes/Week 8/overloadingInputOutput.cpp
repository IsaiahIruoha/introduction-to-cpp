#include <iostream>
#include <string>

/* === Overloading I/O Notes ===
- the << operator takes the RHS, adds it to the stream obtained at the LHS then returns the stream
*/

class Person {
private:
    std::string name;
    int age;

public:
    // Default Constructor
    Person() : name(""), age(0) {}

    // Parameterized Constructor
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Overload '<<' for output
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }

    // Overload '>>' for input
    friend std::istream& operator>>(std::istream& is, Person& p) {
        std::cout << "Enter name: ";
        is >> p.name;
        std::cout << "Enter age: ";
        is >> p.age;
        return is;
    }
};

int main() {
    Person p1;

    // Use overloaded '>>' operator to input data
    std::cin >> p1;

    // Use overloaded '<<' operator to output data
    std::cout << "Person Details: " << p1 << std::endl;

    return 0;
}