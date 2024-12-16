#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <type_traits>

using namespace std;

class Shape {
    public:
        virtual void area() const = 0;
        virtual ~Shape() {}
};

class Rectangle : public Shape {
    private:
        double length, width;

    public:
        Rectangle(double l, double w) : length(l), width(w) {}
        void area() const override {
            cout << length * width << endl;
        }
};

class Circle : public Shape {
    private:
        double radius; 

    public:
        Circle(double r) : radius(r) {}
        void area() const override {
            cout << "Circle Area: " << 3.14159 * radius * radius << endl;
        }
};

class MyArray {
    private:
        int* data;
        size_t size; 

    public:
        MyArray(size_t s) : size(s), data(new int[s]) {
            for (size_t i = 0; i < size; ++i) data[i] = i + 1; 
        }

        ~MyArray() {
            delete[] data;
        }

        MyArray(const MyArray& other) : size(other.size), data(new int[other.size]) {
            for (size_t i = 0; i < size; ++i) data[i] = other.data[i]; 
        }

        int& operator[](size_t index) {
            if (index >= size) throw out_of_range("index out of bounds"); 
            return data[index];
        }

        void display() const {
            for (size_t i = 0; i < size; ++i) cout << data[i] << " "; 
            cout << endl;
        }
};

template <typename T>
T multiply(T a, T b) {
    static_assert(is_arithmetic<T>::value, "Only arithmetic types are supported");
    return a * b;
}

void fileIO() {
    ofstream outFile("output.txt"); 
    if (!outFile) throw runtime_error("Failed to open file for writing"); 
    outFile << "File I/O Example with multiple lines:\n";
    outFile << "Line 1\nLine 2\n";
    outFile.close();

    ifstream inFile("output.txt"); 
    string line; 
    if (!inFile) throw runtime_error("Failed to open file for reading");
    while (getline(inFile, line)) cout << line << endl; 
    inFile.close(); 
}

int main() {

    try {
        vector<Shape*> shapes; 
        shapes.push_back(new Rectangle(5.0, 3.0));
        shapes.push_back(new Circle(4.0));

        for (const auto& shape : shapes) {
            
                shape->area(); // Calls appropriate derived class method
            }

        // Free memory for each shape
        for (auto shape : shapes) {
            delete shape; // Manually clean up heap memory
        }
        shapes.clear();

        // Big Three and Move Semantics
        cout << "\n--- Big Three and Move Semantics ---\n";
        MyArray arr1(5); // Constructor
        arr1.display();

        MyArray arr2 = arr1; // Copy Constructor
        arr2.display();

        MyArray arr3 = move(arr1); // Move Constructor
        arr3.display();
        // arr1 is now empty (data is null)

        // Operator Overloading
        cout << "\n--- Operator Overloading ---\n";
        cout << "Element at index 2 in arr3: " << arr3[2] << endl;

        // Template with Type Traits
        cout << "\n--- Template and Type Traits ---\n";
        cout << "Multiply ints: " << multiply(3, 4) << endl;
        cout << "Multiply doubles: " << multiply(2.5, 1.5) << endl;

        // File I/O
        cout << "\n--- File I/O ---\n";
        fileIO();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}