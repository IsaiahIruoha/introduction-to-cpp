// OnQ Example
// Initilizing constructors
// Constructor overloading
// Creating objects
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
    void set_name(string name_val) { 
        name = name_val; 
    }
    string get_name() {
        return name;
    }
    
    Student() {
        name = "NONE";
        major = "NONE";
        year = 0;
    }

    Student(string name_val) {
        name = name_val;
        major = "NONE";
        year = 0;
    }

    Student(string name_val, string major_val, int year_val) {
        name = name_val;
        major = major_val;
        year = year_val;
    }
    
};

int main() {
    Student kate;
    Student tim {"Tim", "Math", 1};
    Student *abi = new Student ("Abi"); 
    abi->set_name("Abigale"); 
    cout << abi->get_name() << endl;
    delete abi;
    return 0;
}

