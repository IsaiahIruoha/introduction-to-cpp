// ready for onQ 
#include <iostream>
#include <iomanip> // needed for manipulation of the input/ output
using namespace std; 
void ruler() {
    cout << "\n12345678901234567890123456789012345678901234567890" << endl;
}
int main() {
    cout << "*******************BOOLEAN EXAMPLE********************"<< endl; 
    cout << "Boolean manipulation example" <<endl; 
    // default boolean output
    cout << "_________________________________________________________" << endl;
    cout << "default boolean output no manipulator"<< endl; 
    cout << "noboolalpha - default: (5 < 50) is "<< (5 < 50) << endl; 
    cout << "noboolalpha - default: (5 > 50) is "<< (5 > 50) << endl; 
    
    // setting boolean output to true/ false 
    cout << "_________________________________________________________" << endl;
    cout << boolalpha; // will change the default formating for here onwards to true/ false instead of 1/ 0   
    // or 
    // std:: cout.setf(std::ios::boolalpha); 
   
    cout << "Setting `boolalpha` manipulator"<< endl; 
    cout << "boolalpha: (5 < 50) is "<< (5 < 50) << endl; 
    cout << "boolalpha: (5 > 50) is "<< (5 > 50) << endl; 
    
    cout << "_________________________________________________________" << endl;
    cout << "Once the boolalpha is set it continue to display true/ false" << endl; 
    cout << "(2 < 1) is "<< (2 < 1) << endl; 
    cout << "(2 > 1) is "<< (2 > 1) << endl; 
    
    cout << "_________________________________________________________" << endl;
    cout << "Going back to the default using 'noboolalpha' manipulator" << endl; 
    cout <<  noboolalpha;
    // or using memer function unsetf()
    // std:: cout.unsetf(std::ios::boolalpha);
    // or using resetiosflags()
    std::cout << std::resetiosflags (std::ios::boolalpha); 
    
    cout << "noboolalpha : (2 < 1) is "<< (2 < 1) << endl; 
    cout << "noboolalpha : (2 > 1) is "<< (2 > 1) << endl <<endl; 
    
    
    
    cout << "*******************INTEGER EXAMPLE********************"<< endl; 
    cout << "Integer manipulation example" <<endl<<endl; 
    int var = 289; 
     
    cout << var << " in dec - default formatting is: "<< dec << var << endl; 

    cout << showbase << uppercase << endl; // shows the base in uppercase 
    cout << dec << var << " in hex formatting is: "<< hex << var << endl; 
    cout << dec << var << " in oct formatting is: "<< oct << var << endl; 
    
    cout << "____________________________________________________________________"; 
    int n1 {105}; 
    int n2 {-105}; 
    cout << dec << endl; // revert back to dec otherwise 'oct' flag is persistent 

    cout << n1 << endl; 
    cout << n2 << endl; 
    cout << showpos << endl; // adds a plus sign before positive numbers
    cout << "Display '+' sign for positive integers with the 'showpos' flag" << endl; 
    cout << n1 << endl; 
    cout << n2 << endl; 
    
    cout << "____________________________________________________________________"; 
    cout << noshowpos << endl; // comment this out to see that showpos is persistent
// setw, left, right, setfill
    int num1 {1234};
    double num2 {1234.4321};
    string course  {"ELEC376"};

    cout << "*******************FIELDS EXAMPLE********************"<< endl; 
    // by default
    cout << "\n--Defaults -------------------------------------------------------------------" << endl;
    ruler();
    cout << num1
         << num2 
         << course 
         << endl;
    
   // field width to 10 
   // Note applied to num1 only, setw() does not persist!
    cout << "\n--width 10 for num1-----------------------------------------------------------" << endl;
    ruler(); 
    cout << setw(10) << num1
                   << num2          
                   << course 
                   << endl;
    
    // field width to 10 for the first 2 outputs
    cout << "\n--width 10 for num1 and num2------------------------------------------------" << endl;
    ruler(); 
    cout << setw(10) << num1
                   << setw(10) << num2
                   << course 
                   << endl;
                  
    // field width to 10 and left justify for all 3 outputs
    cout << "\n--width 10 for num1 and num2 and course, left for all output ---------------------------" << endl;
    ruler(); 
    cout << setw(10) << left << num1
                   << setw(10) << left << num2
                   << setw(10) << left <<  course
                   << endl;
                  
    // setfill to a dash
    // note: setfill is persistent
    cout << setfill('-');
    cout << "\n--width 10 for num1 and num2 and course left for all setfill to dash------------" << endl;
    ruler(); 
    cout << setw(10) << left << num1
                   << setw(10) << left << num2
                   << setw(10) << left <<  course
                   << endl;

    return 0;  
}
