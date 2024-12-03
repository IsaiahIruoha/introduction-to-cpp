// Types

#include <iostream>

using namespace std;

/*GLOBAL VARIABLES WOULD BE DEFINED HERE, OUTSIDE OF ANY FUNCTION*/
int student_count(50);
char first_initital('A');
string text("Hello, World!");

/* === NOTES ===
- compiler first looks locally then looks globally
- C++ is declarative and statically typed
*/

int main() {
    /* ALL THE FOLLOWING ARE LOCAL VARIABLES*/
   /***** Character type *****/ 
    
    char c1 {'E'};  // single quotes around characters
    cout << "\nc1 is: " << c1 << endl;
    
    /******* Integer types ********/
    unsigned short int test_score {89};  // same as unsigned short test_score
    cout << "\nMy test score was " << test_score << endl;

    int movies_watched {15};
    cout << "\nWe watched " << movies_watched << " movies last year" << endl;


    long ontario_population {14'223'942};
    cout << "\nThe population of Ontario is about " << ontario_population << " people" << endl;
    
                                      
    long long km_to_Proxima_Centauri {40'208'000'000'000};  
    cout << "\nThe distance to alpha centauri is " << km_to_Proxima_Centauri << " kilometers" << endl;
    
   
    /******* Floating point types ********/
    float  price {401.23};
    cout << "\nThe price is " << price << endl;
    
    double pi {3.14159};
    cout << "\nPI is " << pi << endl;
    
    long double large_amount {2.7e120};
    cout << "\n" << large_amount << " is quite a big number" << endl;
    
    /*******  Boolean type ******************/
    bool found {false};
    cout << "\nThe value of found is " << found << endl;
    
    /********* Overflow  **************/
    short value1 {20'000};
    short value2 {1000};
    int product {value1 * value2}; // short will get you an overflow
    
    cout << "\nThe product of " << value1 <<  " and " << value2 << " is " <<  product << endl;

    /******* Escape Sequences *********/
    cout << "\n\nnewline \t tab backspace\b carriage return \r bel \a" << endl;

    /****** Raw Strings *********/
    // Regular string with escape sequences
    std::string regularString = "This is a newline\nand a tab\t.";
    // Raw string with no escape sequences
    std::string rawString = R"(This is a raw string\nand a raw tab\t.)";
    
    std::cout << "Regular String: " << regularString << std::endl;
    std::cout << "Raw String: " << rawString << std::endl;


    /********* Constants *********/
    /* older constans used the #define, in c++ we can use the const prequalifier*/
    const int MONTHS =12;
    const double GRAVITY = 9.81;

    //enumerated constants
    enum Days {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

   /*constant expressions
   - get evaluated at runtime
   - save performance
   */
    constexpr int add(int a, int b){
        return a + b;
    }

    constexpr int result = add(3, 4);
    cout << result << endl;

    return 0;
}

