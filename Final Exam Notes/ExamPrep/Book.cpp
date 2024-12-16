#include "Book.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string> 

using namespace std; 

Book::Book() : id(0), title("No Title Provided"), author("No Author Provided") {}
Book::Book(int id, const string& title, const string& author) : id(id), title(title), author(author) {}

ostream& operator<<(ostream& os, const Book& book) {
    os << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author;
    return os;
}

void Book::saveToFile(ofstream& file) const {
    if (!file.is_open()) {
        cerr << "Error: File could not be opened for writing.\n";
        return;
    }
    file << id << " " << title << " " << author << "\n";
}


Book Book::loadFromFile(ifstream& file) {
    if (!file.is_open()) {
        cerr << "Error: File is not open for reading.\n";
        return Book(); // Return a default-constructed Book
    }

    int id;
    string title, author;
    file >> id >> title >> author;

    return Book(id, title, author);
}

int main () {
    vector<Book> books; 
    string filename = "books.txt"; 
    char choice;

    while(true) {
        cout << "\n--- Book Catalog Management ---\n";
        cout << "1. Add a Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Save Books to File\n";
        cout << "4. Load Books from File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            int id;
            string title, author;

            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);

            books.emplace_back(id, title, author); 
            cout << "Book added successfulley!\n"; 
        }
        else if (choice == '2') {
            for(const auto& book : books) {
                cout << book; 
            };
        }
        else if (choice == '3') {
            ofstream outFile(filename);
            if (!outFile) {
                cerr << "Error: Unable to open file for saving.\n";
            } else {
                for(const auto& book : books) {
                    book.saveToFile(outFile); 
                };
            } 
        }
        else if (choice == '4') {
            ifstream inFile(filename); 
            if (!inFile) {
                cerr << "Error: Unable to open file for saving.\n"; 
            } else {
                while (inFile) {
                    Book book = Book::loadFromFile(inFile);
                    if (book.getId() != 0) { // Check for a valid Book
                        books.push_back(book);
                    }
                }
            }
        }
        else if (choice == '5') {
            cout << "Exiting Program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}