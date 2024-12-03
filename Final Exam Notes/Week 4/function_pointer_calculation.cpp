#include <iostream>
#include <vector>
#include <string>
using namespace std; 

#include <iostream>

// Function prototypes for calculator operations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Function pointer type

int main() {
    int num1, num2;
    char op;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    // Declare a function pointer
    int (*Operation)(int, int);

    // Assign the appropriate function based on user input
    switch (op) {
        case '+':
            Operation = add;
            break;
        case '-':
            Operation = subtract;
            break;
        case '*':
            Operation = multiply;
            break;
        case '/':
            Operation = divide;
            break;
        default:
            std::cerr << "Invalid operation\n";
            return 1;
    }

    // Use the function pointer to perform the selected operation
    int result = Operation(num1, num2);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

// Function definitions for calculator operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cerr << "Cannot divide by zero\n";
        return 0;
    }
}
