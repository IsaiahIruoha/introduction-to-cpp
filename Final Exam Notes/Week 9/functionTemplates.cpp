#include <iostream>
#include <string>
#include <vector>

/* === Function Template Notes ===
- is a blueprint
- compiler generates appropriate function / class from the template
- no limit on number of template parameters
*/

// 1. Basic Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// 2. Function Template with Multiple Parameters of Different Types
template <typename T, typename U>
auto multiply(T a, U b) -> decltype(a * b) {
    return a * b;
}

// 3. Function Template Specialization
template <typename T>
T square(T value) {
    return value * value;
}

// Specializing the square function for string types
template <>
std::string square<std::string>(std::string value) {
    return value + value;  // Concatenates the string with itself
}

// 4. Function Template with Default Arguments
template <typename T>
T divide(T a, T b = 1) {
    return a / b;
}

// 5. Template with a Reference Type
template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

int main() {
    // 1. Basic Function Template Example
    int int_result = add(3, 4);  // Works with integers
    std::cout << "add(3, 4): " << int_result << "\n";

    double double_result = add(3.5, 4.5);  // Works with doubles
    std::cout << "add(3.5, 4.5): " << double_result << "\n";

    // 2. Function Template with Multiple Parameters of Different Types
    auto product_result = multiply(3, 4.5);  // Works with int and double
    std::cout << "multiply(3, 4.5): " << product_result << "\n";

    // 3. Function Template Specialization
    int int_square = square(5);  // Works with int
    std::cout << "square(5): " << int_square << "\n";

    std::string str_square = square(std::string("Hello"));  // Specialized for string
    std::cout << "square(\"Hello\"): " << str_square << "\n";

    // 4. Function Template with Default Arguments
    double division_result = divide(10.0);  // Uses default value for b
    std::cout << "divide(10.0): " << division_result << "\n";
    double division_result2 = divide(10.0, 2.0);  // Custom value for b
    std::cout << "divide(10.0, 2.0): " << division_result2 << "\n";

    // 5. Template with a Reference Type
    int x = 10;
    std::string str = "Hello, World!";
    print(x);  // Prints integer
    print(str);  // Prints string

    return 0;
}
