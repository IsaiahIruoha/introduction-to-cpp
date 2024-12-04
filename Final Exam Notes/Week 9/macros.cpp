#include <iostream>

/* === Macros Notes ===
- Generic programming is a style of computer programming in which algorithms are
written in terms of data types to-be-specified-later that are then instantiated when
needed for specific types provided as parameters.
- C++ compiler is statically typed so how do we make this work?
    - use macros
- macros begin with the # sign
- preprocessor directive
- no type information compared to const
*/

// 1. Constant Macro
#define PI 3.14159
#define MAX_BUFFER_SIZE 1024

// 2. Function-like Macro
#define SQUARE(x) ((x) * (x)) // good macro
#define BADSQUARE(x) x*x // bad macro
#define CUBE(x) ((x) * (x) * (x))

// 3. Conditional Compilation
#define DEBUG

// 4. Stringizing Macro
#define TO_STRING(x) #x

// 5. Concatenation Macro
#define CONCAT(a, b) a ## b

int main() {
    // 1. Using a constant macro
    std::cout << "PI is: " << PI << "\n";
    std::cout << "Max Buffer Size is: " << MAX_BUFFER_SIZE << "\n";

    // 2. Using function-like macros
    int num = 5;
    std::cout << "Square of " << num << " is: " << SQUARE(num) << "\n";
    std::cout << "Cube of " << num << " is: " << CUBE(num) << "\n";

    std::cout << "using good square 100 / 5^2: " << 100 / SQUARE(num) << "\n";
    std::cout << "using bad square 100 / 5^2: " << 100 / BADSQUARE(num) << "\n";

    std::cout << "issue " << 100 / SQUARE(num) << std::endl;

    // 3. Conditional Compilation: This will only be included if DEBUG is defined
#ifdef DEBUG
    std::cout << "Debugging is enabled\n";
#else
    std::cout << "Debugging is not enabled\n";
#endif

    // 4. Stringizing Macro
    std::cout << "Stringizing the number 100: " << TO_STRING(100) << "\n";

    // 5. Concatenation Macro
    int myVar123 = 10;
    std::cout << "Value of concatenated variable myVar123: " << CONCAT(myVar, 123) << "\n"; 

    return 0;
}
