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
#include <sstream> // For splitting hyphenated words
using namespace std; 

// Function prototype for counting word frequency
void countWordFrequency(ifstream& inData, const string& word, int& total_words, int& word_count);

// Function prototype for toLowerCase
string toLowerCase(string str);

// Function prototype for removePunctuation
string removePunctuation(string word);

// Function prototype for splitting hyphenated words
bool containsWord(const string& word, const string& searchWord);

int main() {
    string searchWord = ""; 
    cout << endl; 
    cout << "Hi there! This program outputs the number of times" << endl
         << "a word appears in Hamlet by William Shakespeare." << endl; 
    cout << "Please enter the word to search for: ";
    cin >> searchWord;
    
    // Store original word for output
    string originalWord = searchWord;
    
    // Convert input word to lowercase
    searchWord = toLowerCase(searchWord);
    
    // Open the file
    ifstream inFile("hamlet.txt");
    int foundCount = 0, totalWords = 0;

    // Check if file is successfully opened 
    if (inFile.is_open()) {
        // Call function to find the word provided by the user
        countWordFrequency(inFile, searchWord, totalWords, foundCount);
    } else {
        cout << "Failed to open file!" << endl;
        return 1; // Exit if the file can't be opened
    }
    
    // Close the file
    inFile.close();
    
    // Output to the console the total number of words searched, the word provided by the user and the number of occurrences of that word in the file
    cout << totalWords << " words were searched, and the word '" << originalWord
         << "' was found " << foundCount << " times." << endl;
    
    return 0;
}

// Convert a string to lowercase
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c); // Convert each char to lowercase
    }
    return str;
}

// Remove punctuation, but keep hyphens inside a word
string removePunctuation(string word) {
    string result = "";
    for (int i = 0; i < word.length(); ++i) {
        char c = word[i];
        if (isalnum(c) || (c == '-' && i > 0 && i < word.length() - 1)) {
            result += c;
        }
    }
    return result;
}

// Check if the word is present in the current word or its hyphenated parts
bool containsWord(const string& word, const string& searchWord) {
    if (word == searchWord) {
        return true;
    }

    // Split the word by hyphens and check each part
    stringstream ss(word);
    string part;
    while (getline(ss, part, '-')) {
        if (part == searchWord) {
            return true;
        }
    }
    return false;
}

// Count the frequency of a word in the file
void countWordFrequency(ifstream& inData, const string& word, int& total_words, int& word_count) {
    string current_word;
    
    // Read the file word by word
    while (inData >> current_word) {
        current_word = removePunctuation(toLowerCase(current_word)); // Lowercase and clean up word
        total_words++;

        // Check if the current word contains the searched word
        if (containsWord(current_word, word)) {
            word_count++;
        }
    }
}
