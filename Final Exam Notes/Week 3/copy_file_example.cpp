#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main() {
    ifstream fileIn{"aboutCplusplus.txt"}; 
    ofstream fileOut{"aboutCplusplus_copy.txt"}; 
    
    if (!fileIn) {
        cerr << "error opening input file" << endl; 
        return -1; 
    }
    
    if (!fileOut) {
        cerr << "error opening output file" << endl; 
        return -1; 
    }
    
    /*line by line */
    string line{}; 
    int line_num {0}; 
    while (!fileIn.eof()){
        getline(fileIn, line);
        if (line != ""){
            fileOut << ++line_num  << " " << line << endl; 
        }
        else {
            fileOut << line << endl; 
        }
    }
    
    /*or char by char
    
    char c; 
    while (fileIn.get(c)){
        fileOut.put(c); 
    }
    */
    cout << "File copied" << endl;  
    fileIn.close(); 
    fileOut.close(); 
    
    return 0;  
}