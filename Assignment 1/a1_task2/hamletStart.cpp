/* The program allows users to find and report the frequency 
 * of a specific word within the text of "Hamlet." 
 * The program prompts the user to enter a word, 
 * reads the text from the "hamlet.txt" file, and searches
 * for occurrences of the word within the words of the text. 
 * It then displays the total number of words searched and the count 
 * of how many times the word was found within those words. */

#include <iostream>
#include <fstream>
#include <string> 
using namespace std; 

//function protoype for toLowerCase
string toLowerCase(string str) {
    for (char &c : str) { // pass by reference
        c = tolower(c);
    }
    return str;
}

int main() {
    string word = ""; 
    cout << endl; 
    cout << "Hi there! this outputs the number of times"<< endl <<  "a word appears in Hamlet by William Shakespeare" << endl; 
    cout << endl;
    cout << "Please enter the word to search for:" << endl;
    cin >> word; 

    word = toLowerCase(word);
    
    // open file
    ifstream inFile;
    inFile.open("hamlet.txt");
    string wordToFind = "";
    int foundCount = 0;
    int totalWords = 0;


    // check file is successfully open 
    if (inFile.is_open()) {
        // read file 
        while (inFile >> wordToFind) {
            wordToFind = toLowerCase(wordToFind);
            if (wordToFind == word) {
                foundCount++;
            }
            totalWords++;
        }
    } else {
        cout << "File is not successfully open" << endl;
    }
    
    // close file
    inFile.close();
    // output to the console the total number of words searched, the word provided by the user and the number of occurrences of that word in the file
    cout << totalWords << " were searched and the word " << word << " was found " << foundCount << " times" << endl;
    return 0;  
}