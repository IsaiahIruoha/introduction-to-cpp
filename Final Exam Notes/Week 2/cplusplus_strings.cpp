#include <iostream>
#include <string>

using namespace std; // or use std:: 

int main() {

    string emptyItem;
    string item1 {"pencil"};
    string item2 {"paper"};
    string item3 {"pc"};
    string item4 {"bottle"};
    string itemCopy {item1};
    string partialCopy {item1, 0, 3};
    string repeatedA (7, 'A');  

    cout << emptyItem << endl; // empty string
    cout << emptyItem.length() << endl; // 0

    cout << itemCopy << endl; 
    cout << partialCopy << endl; 
    cout << repeatedA << endl; 

    // Comparison

    cout << "\nComparison ============================" << endl; 
    cout << boolalpha; // displays true or false  
    cout << item1 << " == " << itemCopy << ": " << (item1 == itemCopy) << endl;             
    cout << item1 << " != " << item2 << ": " << (item1 != item2) << endl;                  
    cout << item1 << " < " << item2 << ": " << (item1 < item2) << endl;;                    
    cout << item1 << " == " << "pen" << ": " << (item1 == "pen") << endl;;               

    // Assignment 
    cout << "\nAssignment ============================" << endl; 
    item1 = "notebook";
    cout << "item1 is now: " << item1 << endl;    
    item2 = item1;
    cout << "item2 is now: " << item2 << endl;    

    item3 = "Eraser";
    cout << "item3 is now: " << item3 << endl;    

    item3[0] = 'C';    
    cout << "item3 change first letter to 'C': "  << item3 << endl;   
    item3.at(0) = 'P';
    cout << "item3 change first letter to 'P': "  << item3 << endl;   

    // Concatenation
    cout << "\nConcatenation============================" << endl; 
    item3 = "Pen";
    item3 =  itemCopy + " and " + item2;     
    cout << "item3 is now: " << item3 << endl;        
    //item3 = "new and" + " sharp " + itemCopy;   // Compiler error

    cout << "\nLooping ============================" << endl; 
    item1 = "Pen";
    for (size_t i {0}; i < item1.length(); ++i) 
        cout << item1.at(i);      
    cout << endl;       

    // Substring
    cout << "\nSubstring ============================" << endl; 
    item1 = "This is a notepad";
    cout << item1.substr(0,4) << endl;     // This
    cout << item1.substr(5,2) << endl;     // is
    cout << item1.substr(10,4) << endl;    // note

    cout << "\nString length ============================" << endl; 
    string aString ("Stationery item");
    cout << "The length of aString is " << aString.length() << endl; 

    // getline
    cout << "\ngetline============================" << endl; 
    string fullName {};
   
    cout << "Enter your full name: ";
    getline(cin, fullName);
   
    cout << "Your full name is: " << fullName << endl;
    
    // find
    cout << "\nfind============================" << endl; 
    item1 = "Hello ELEC 376 class";
    string targetWord {};
   
    cout << "Enter the word to search for: ";
    cin >> targetWord;
   
    size_t position = item1.find(targetWord);
    if (position != string::npos)
        cout << "Found " << targetWord << " at position: " << position << endl;
    else
        cout << targetWord <<  " is not found" << endl;

    cout << endl;
    return 0;
}
