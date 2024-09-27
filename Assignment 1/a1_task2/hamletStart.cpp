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

// function prototype for counting word frequency
void countWordFrequency(ifstream& inData, const string& word, int& total_words, int& word_count);

// function prototype for toLowerCase
string toLowerCase(string str);

int main() {
    string word = ""; 
    cout << endl; 
    cout << "Hi there! This outputs the number of times" << endl
         << "a word appears in Hamlet by William Shakespeare." << endl; 
    cout << "Please enter the word to search for: ";
    cin >> word;
    
    // convert input word to lowercase
    word = toLowerCase(word);
    
    // open the file
    ifstream inFile("hamlet.txt");
    int foundCount = 0, totalWords = 0;

    // check if file is successfully open 
    if (inFile.is_open()) {
        // call function to find the word provided by the user
        countWordFrequency(inFile, word, totalWords, foundCount);
    } else {
        cout << "Failed to open file!" << endl;
        return 1; // exit if the file can't be opened
    }
    
    // close the file
    inFile.close();
    
    // output to the console the total number of words searched, the word provided by the user and the number of occurrences of that word in the file
    cout << totalWords << " words were searched, and the word '" << word
         << "' was found " << foundCount << " times." << endl;
    
    return 0;
}

// convert a string to lowercase
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c); // convert each char to lowercase
    }
    return str;
}

// remove punctuation, but keep hyphens inside a word
string removePunctuation(string word) {
    string result = "";
    for (size_t i = 0; i < word.length(); ++i) {
        char c = word[i];
        if (isalnum(c) || (c == '-' && i > 0 && i < word.length() - 1)) {
            result += c;
        }
    }
    return result;
}

// count the frequency of a word in the file
void countWordFrequency(ifstream& inData, const string& word, int& total_words, int& word_count) {
    string current_word;
    
    // read the file word by word
    while (inData >> current_word) {
        current_word = removePunctuation(toLowerCase(current_word)); // lowercase and clean up word
        total_words++;

        // check if it's an exact match or a hyphenated match
        if (current_word == word || current_word.find(word + "-") == 0) {
            word_count++;
        }
    }
}
