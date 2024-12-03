// onQ
// Introduction to Constructors and Destructors
// Overloading contructors 
// See when and which constructor is called 
// See when destructor is called

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

    // Overloaded Constructors
    Student() { 
        cout << "No args constructor called"<< endl;
    }
    Student(string name_val) { 
        cout << "Single arg constructor called"<< endl;
    }
    Student(string name_val, string major_val, int year_val) {
        cout << "Three args constructor called"<< endl; 
    }
    // Destructor
    ~Student() { 
        cout << "Destructor called for " << name << endl; 
    }
};

int main() {
    // These blocks are added to see when the destructor is called 
    {
        Student sarah;
        sarah.set_name("Sarah");
    }
    
    {   // Notice the destructor is called in the oposite order of the constructors
        Student mark;
        mark.set_name("Mark");

        Student ben("Ben");
        ben.set_name("Ben");

        Student kate("Kate", "Computer Engineering", 2);
        kate.set_name("Kate");
    }
    
    Student *john = new Student;
    john->set_name("John");
    
    Student *abi = new Student("abi", "Biology", 3);
    (*abi).set_name("Abi"); // equivalent to abi->set_name("abi")
    
    delete john;
    delete abi;
    
    return 0;
}

