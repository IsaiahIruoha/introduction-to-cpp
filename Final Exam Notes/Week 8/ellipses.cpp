#include <iostream>
#include <cstdarg>

/* === Ellipses Notes ===
- used to define variadic functions
- variadic function is one that can accept a variable number of arguments
- used when the number of parameters is not known at compile time
*/

void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count); // Initialize the argument list

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int); // Retrieve the next argument
        std::cout << num << " ";
    }
    std::cout << std::endl;

    va_end(args); // Clean up
}

int main() {
    printNumbers(3, 10, 20, 30); // Pass three integers
    printNumbers(5, 1, 2, 3, 4, 5); // Pass five integers
    return 0;
}
