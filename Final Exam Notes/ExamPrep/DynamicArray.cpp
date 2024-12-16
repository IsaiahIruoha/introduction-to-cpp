#include <iostream>

using namespace std;

class DynamicArray {
    private:
        int* data;  // Pointer to the dynamic array
        size_t size; // Size of the array

    public:
        // Constructor 
        DynamicArray(size_t s) : size(s) {
            cout << "Constructor called. Allocating array of size " << size << ".\n";
            data = new int[size]; 
        }; 
        
        // Destructor
        ~DynamicArray() {
            cout << "Destructor called. Freeing memory.\n"; 
            delete[] data; 
        }; 

        // Copy Constructor
        DynamicArray(const DynamicArray& other) : size(other.size) {
            cout << "Copy Constructor called. Creating deep copy.\n"; 
            data = new int[size]; 
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i]; 
            }
        }

        // Operator overriding 
        DynamicArray& operator=(const DynamicArray& other) {
            cout << "Copy Assignment Operator called.\n";

            if (this == &other) {
                cout << "Self-assignment detected. No action taken.\n"; 
                return *this; 
            }

            // Free current memory
            delete[] data;

            // Allocate new memory and copy data
            size = other.size;
            data = new int[size]; 
            for(size_t i = 0; i < size; ++i) {
                data[i] = other.data[i]; 
            }

            return *this; 
        }

        // Display the array
        void display() const {
            for (size_t i = 0; i < size; i++) {
                cout << data[i] << " "; 
            }
            cout << endl; 
        }

        // Set a value at a given index
        void set(size_t index, int value) {
            if (index < size) {
                data[index] = value; 
            } else {
                cerr << "Index out of bounds!.\n"; 
            }
        }

        // Get size of the array
        size_t getSize() const {
            return size; 
        }
}; 

int main() {
    // Step 1: Create a DynamicArray object
    DynamicArray arr1(5);
    for (size_t i = 0; i < arr1.getSize(); ++i) {
        arr1.set(i, i * 10); // Set values: 0, 10, 20, 30, 40
    }
    cout << "arr1 contents: ";
    arr1.display();

    // Step 2: Test the Copy Constructor
    DynamicArray arr2 = arr1; // Deep copy
    cout << "arr2 (copied from arr1) contents: ";
    arr2.display();

    // Step 3: Test the Copy Assignment Operator
    DynamicArray arr3(3);
    arr3 = arr1; // Deep copy assignment
    cout << "arr3 (assigned from arr1) contents: ";
    arr3.display();

    // Step 4: Test manual destruction (implicit with scope)
    cout << "Exiting program. Destructors will be called.\n";

    return 0;
}