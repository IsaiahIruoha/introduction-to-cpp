#include <iostream>
using namespace std;

/* === Friend Functions Notes
- function that is declared as a friend can be implemented as a non-member function but can still access and change private attributes
- function prototype must be inside the class definition
- convienient but, they break privacy rules of OOP, do not have access to this pointer
*/

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Friend function to calculate volume
    friend double calculateVolume(const Box& b);

    // Friend function to display dimensions
    friend void displayDimensions(const Box& b);
};

// Definition of the friend function to calculate volume
double calculateVolume(const Box& b) {
    return b.length * b.width * b.height;
}

// Definition of the friend function to display dimensions
void displayDimensions(const Box& b) {
    cout << "Length: " << b.length << ", Width: " << b.width << ", Height: " << b.height << endl;
}

int main() {
    Box myBox(5.0, 3.0, 2.0);

    // Use the friend function to calculate volume
    double volume = calculateVolume(myBox);
    cout << "Volume of the box: " << volume << endl;

    // Use the friend function to display dimensions
    displayDimensions(myBox);

    return 0;
}