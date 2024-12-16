#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

class Book {
    private:
        int id; 
        string title; 
        string author;
    
    public:

        // Constructors
        Book();    // Default Constructors
        Book(int id, const string& title, const string& author);

        // Friend Function: Overloaded Output Operator
        friend ostream& operator<<(ostream& os, const Book& book);  

        // Save and Load Book to/from File 
        void saveToFile(ofstream& outFile) const; 
        static Book loadFromFile(ifstream& inFile);

        // Getters for display
        int getId() const { return id; }
        string getTitle() const { return title; }
        string getAuthor() const { return author; }
}; 

class FileIOException : public runtime_error {
    public:
        FileIOException(const string& message) : runtime_error(message) {}
}; 