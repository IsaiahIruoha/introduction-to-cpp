// OnQ Example
// Delegating Constructors
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
    Student();
    Student(string name_val);
    Student(string name_val, string major_val, int year_val);
};


Student::Student() 
    : Student {"NONE","NONE",0} {
        cout << "No-args constructor delegated to three args constructor" << endl;
}

Student::Student(string name_val) 
   : Student {name_val,"NONE", 0}  {
           cout << "One-arg constructor delegated to three args constructor" << endl;
}
  
Student::Student(string name_val, string major_val, int year_val) 
    : name{name_val}, major{major_val}, year{year_val} {
            cout << "Three-args constructor" << endl;
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
    Student sarah;
    Student tim {"Tim"};
    Student kate {"Kate", "electrical engineering", 3};
    cout << "*************************************************" << endl; 
    cout << kate.get_name() << " is in year " << kate.get_year() << " of her " << kate.get_major() << " degree" << endl; 
    return 0;
}

