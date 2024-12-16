#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <type_traits>
using namespace std;

// Base class 
class Base {
    public:
        virtual void display() const { 
            cout << "Base Class" << endl; 
        }
        virtual ~Base() {} // Polymorphic base destructor
}; 

// Derived class
class Derived : public Base {
    public:
        void display() const override { cout << "Derived Class" << endl; }
}; 

// Clas demonstrating the "Big Three"
class MyClass {
    private:
        int* data;
    
    public:
        // Constructor
        MyClass(int value = 0) : data(new int(value)) {
            cout << "Constructor called: " << *data << endl; 
        }

        // Destructor
        ~MyClass() {
            delete data; 
            cout << "Destructor Called" << endl; 
        }

        // Copy Constructor
        MyClass(const MyClass& other) : data(new int(*other.data)) {
            cout << "Copy Constructor called" << endl;
        }

        // Copy Assignment Operator
        MyClass& operator=(const MyClass& other) {
            if (this != &other) {
                *data = *other.data; 
            }
            cout << "Copy Assignment Operator Called" << endl; 
            return *this; 
        }

        // Display Method
        void show() const {
            cout << "Data: " << *data << endl; 
        }
}; 

// Overloading an operator
class Vector3D {
    private:
        float x, y, z;

    public:
        Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    
        // Operator overload for addition
        Vector3D operator+(const Vector3D& other) const {
            return Vector3D(x + other.x, y + other.y, z + other.z); 
        }

        // Display Method
        void display() const {
            cout << "Vector(" << x << ", " << y << ", " << z << ")" << endl;
        }
};

// Template Function
template <typename T> 
T add(T a, T b) {
    return (a+ b);
}

// File I/O
void fileIO () {
    ofstream outFile("example.txt");
    outFile << "File IO  Example\n";
    outFile.close();

    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << "File content: " << line << endl; 
    }
    inFile.close(); 
}

int main() {

    // Inheritance and Polymorphism
    Base* basePtr = new Derived();
    basePtr->display(); 
    delete basePtr; 

    // Big Three
    MyClass obj1(10); 
    MyClass obj2 = obj1; 
    MyClass obj3;
    obj3 = obj1;
    obj1.show(); 
    obj2.show();
    obj3.show();

    // Operator Overloading
    Vector3D v1(1.0f, 2.0f, 3.0f), v2(4.0f, 5.0f, 6.0f); 
    Vector3D v3 = v1 + v2; 
    v3.display();

    

    return 0; 
}