#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std; 

int main() {
    ofstream fileOut; 
    fileOut.open("output_saved.txt", ios::app); 
    
    if (!fileOut) {
            cerr << "error creating file" <<endl; 
            return -1; 
    }
    
    string line; 
    cout << "Enter a line to enter to a file " << endl; 
    getline(cin, line); // because we are reading more than one word
    fileOut << line << endl; 
    fileOut.close(); 
    
    return 0;  
}