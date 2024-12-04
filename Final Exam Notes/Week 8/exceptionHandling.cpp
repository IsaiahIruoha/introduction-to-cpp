#include <iostream>
#include <stdexcept> // For standard exceptions like std::out_of_range

/* === Exception Handling Notes ===
- about dealing with exceptional situations
- Detect an exceptional situtation, Deal with the exceptional situation
- Exception: object or primitive type that shows an error has happened
- throwing: code detects and signals an error has or is about to occur
- catching: code that knows what to do in case of exception
- best practice it to throw by value and catch by reference
- exceptions from functions is when an exception is thrown in the function,
  and then caught in main
- catch all handler (...) catchees all exceptions
- Stack Unwinding
    - once exception is thrown, looks first for catch in current scope
    - it not caught, looks for a handler by unwinding the stack
    - function terminates and is removed from the stack, then looks for catch block
    - if not, unwinds stack again
    - until it reaches main where if not exception handler is found, program terminates
- Exception Classes
    - can use attributes and methods to make exceotion more descriptive
    - std::exception is the base class
    - all other classes are derived from it
    - must implement the what() virtual function
*/

void divideByZero() {
    throw std::runtime_error("Division by zero is not allowed.");
}

void accessOutOfRange() {
    throw std::out_of_range("Index is out of range.");
}

void invalidCast() {
    throw std::bad_cast();
}

void customException() {
    class CustomException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "This is a custom exception!";
        }
    };

    throw CustomException();
}

// Function to demonstrate stack unwinding
void functionC() {
    std::cout << "In functionC." << std::endl;
    throw std::runtime_error("Error in functionC.");
}

void functionB() {
    std::cout << "In functionB." << std::endl;
    functionC(); // Calls functionC
}

void functionA() {
    std::cout << "In functionA." << std::endl;
    functionB(); // Calls functionB
}

int main() {
    try {
        // Example of a runtime error
        divideByZero();
    } catch (const std::runtime_error& e) {
        std::cout << "Runtime error caught: " << e.what() << std::endl;
    }

    try {
        // Example of out-of-range access
        accessOutOfRange();
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range error caught: " << e.what() << std::endl;
    }

    try {
        // Example of a bad cast
        invalidCast();
    } catch (const std::bad_cast& e) {
        std::cout << "Bad cast caught: " << e.what() << std::endl;
    }

    try {
        // Example of a custom exception
        customException();
    } catch (const std::exception& e) {
        std::cout << "Custom exception caught: " << e.what() << std::endl;
    }

    try {
        // Generic catch block for all exceptions
        throw "A generic exception!";
    } catch (...) {
        std::cout << "Generic catch block triggered." << std::endl;
    }

    try {
        // Stack unwinding example
        functionA();
    } catch (const std::exception& e) {
        std::cout << "Exception caught during stack unwinding: " << e.what() << std::endl;
    }

    return 0;
}