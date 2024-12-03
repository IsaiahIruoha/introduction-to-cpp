// using sizeof operator

#include <iostream>
#include <climits>      
// Similar information for floating point numbers in <cfloat>

using namespace std;

int main() {

    cout << "size information" << endl;
    cout << "-------------------------" << endl;
    
    cout << "char: " << sizeof(char) << " bytes." << endl;
    cout << "int : " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    cout << "long long: " << sizeof(long long) << " bytes." << endl;
    
    cout << "-------------------------" << endl;

    cout << "float: " << sizeof(float) << " bytes." << endl;
    cout << "double: " << sizeof(double) << " bytes." << endl;
    cout << "long double: " << sizeof(long double) << " bytes." << endl;
//
//
    // using <climits>
    cout << "-------------------------" << endl;
    
    cout << "Minimum values:" << endl;
    cout << "char: " << CHAR_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "long: " << LONG_MIN << endl; 
    cout << "long long: " << LLONG_MIN << endl;
//     
    cout << "-------------------------" << endl;
    
    cout << "Maximum values:" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl; 
    cout << "long long: " << LLONG_MAX << endl;
//    
    // using size of with var names
    cout << "-------------------------" << endl;
    
    cout << "sizeof using variable names" << endl;
    int count {21};
    cout << "age is " << sizeof(count) << " bytes." << endl;
    // or
     cout << "age is " << sizeof count << " bytes." << endl;
     
    double price { 22.24};
    cout << "price is " << sizeof(price) << " bytes." << endl;
    // or
    cout << "wage is " << sizeof price << " bytes." << endl;


    return 0;
}

