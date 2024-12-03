// OnQ Example
// Constructor Initialization Lists and default values
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
   string name;
   string major;
   int year;
public:
    string get_name(); 
    string get_major(); 
    int get_year(); 
    // Overloaded Constructors
    /**
        Student();
        Student(string name_val);
        Student(string name_val, string major_val, int year_val);
    **/

    // This constructor with default values replaces all above constructors 
    Student(string name_val ="None", string major_val = "NONE", int year_val = 0);
};
/**
Student::Student() 
    : name{"NONE"}, major{"NONE"}, year{0} {
        cout << "No arg constructor called" << endl; 
}

Student::Student(string name_val) 
   : name{name_val}, major{"NONE"}, year{0} {
        cout << "One arg constructor called" << endl;
}
**/  
Student::Student(string name_val, string major_val, int year_val) 
    : name{name_val}, major{major_val}, year{year_val} {
        cout << "Three args constructor called" << endl; 
}
// getters
string Student::get_name() {
    return name; 
}
string Student::get_major(){
    return major; 
}
int Student::get_year(){
    return year; 
}

int main() {
    
    Student abi;
    Student tim {"Tim"};
    Student kate {"Kate", "mechanical engineering", 4};
    cout << kate.get_name() << " is in year " << kate.get_year() << " of her " << kate.get_major() << " degree" << endl; 
    
    return 0;
}

