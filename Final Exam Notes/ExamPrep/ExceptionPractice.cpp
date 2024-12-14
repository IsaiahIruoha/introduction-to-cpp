#include <iostream> 

using namespace std; 


class ZeroDivision : public runtime_error {
    public:
        explicit ZeroDivision(const string& message) : runtime_error(message) {}
};


int main () {

    float f1, f2, result; 

    cin >> f1;
    cin >> f2; 

    try {
        if (f2 == 0) {
            throw ZeroDivision("Division By Zero"); 
        }
        result = f1/f2;
    } catch (const ZeroDivision &e) {
        cerr << e.what() << endl; 
    }
}
