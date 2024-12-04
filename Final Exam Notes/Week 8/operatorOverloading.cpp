#include <iostream>

/* === Operator Overloading Notes ===
- allows operators to be redefined to work with user-defined types
- an overloaded operator is only used when one or the other, or both are of your class type
- cannot create new operators
- cannot change associativity or order of precedance
- operators that CANNOT be overloaded: . (member access) * (pointer to member access) :: (scope resolution) ? (ternary conditional)
- cannot change number of operands an operator takes (unary takes one, binary takes two)
*/

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload '+' operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload '-' operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload '*' operator
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Overload '==' operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload '!=' operator
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload '<<' for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return os;
    }
};

int main() {
    Complex c1(3, 4); // 3 + 4i
    Complex c2(1, -2); // 1 - 2i

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    std::cout << "c1: " << c1 << "\n";
    std::cout << "c2: " << c2 << "\n";
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Difference: " << difference << "\n";
    std::cout << "Product: " << product << "\n";

    if (c1 == c2) {
        std::cout << "c1 and c2 are equal." << std::endl;
    } else {
        std::cout << "c1 and c2 are not equal." << std::endl;
    }

    return 0;
}
