#include <iostream>
#include <fstream>
using namespace std; 

// reading from a file

int main() {
    ifstream fileIn;
    string make;
    string model; 
    int year; 
    string color; 
    int km_driven; 
    double price; 
    string line; // if using getline()
    fileIn.open("test.txt");
    if (!fileIn) // same as  if (!fileIn.is_open())
    {
        cerr << "Error: problem opening file" << endl;
        return -1;
    }
    
    while (!fileIn.eof()) 
    // same as while (fileIn >> make >> model >> year >> color >> km_driven >> price) 
    {   
        //line by line using getline()
        // getline(fileIn, line); 
        // cout << line <<endl; 
        
        // or 
        fileIn >> make >> model >> year >> color >> km_driven >> price; 
        cout << setw(10) << left << make 
                       << setw(10)  << model 
                       << setw(10)  << year
                       << setw(10)  << color
                       << setw(10)  << km_driven
                       << setw(10)  << price
                       << endl;
                    
                       
    }
    return 0;
}