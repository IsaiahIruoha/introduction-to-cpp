// Week 2 - Arrays
#include <iostream>
using namespace std;

/* === Array notes ===
- Array name is the location of the first element of the array
- [index] is the offset from the start of the array
- no bounds checking is done with arrays
*/

int main() {

    // non initialized array --> garbage data 
    double lo_temps [4]; 
    cout << endl; 
    cout << "The first low temperature is " << lo_temps[0] << endl; 
    cout << "The second low temperature is " << lo_temps[1] << endl << endl; 
    cout << "=============================================" << endl; 
    cout << endl; 

    // array init list -- automaticaly calculated size
    char vowels[] {'a' ,'e', 'i', 'o', 'u' };
    cout << "The first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl << endl;
    cout << "=============================================" << endl; 
    cout << endl; 

    // array init list
    double hi_temps [5] {25.5, 18.9, 27.1, 15.8}; // last element automatically initialized to 0
    cout << "The first high temperature is: " << hi_temps[0] << endl;
    cout << "The last high temperature is: " << hi_temps[4] << endl; 
    hi_temps[0] = 20.5;    // set the first element in hi_temps to 20.5 
    cout << "The first high temperature is now: " << hi_temps[0] << endl << endl;
    cout << "=============================================" << endl; 
    cout << endl; 

    // array init list and updating it
    int test_scores [] {95, 60, 80,70, 00};
    cout << "First score at index 0: " << test_scores[0] << endl;
    cout << "Second score at index 1: " << test_scores[1] << endl;
    cout << "Third score at index 2:  " << test_scores[2] << endl;
    cout << "Fourth score at index 3: " << test_scores[3] << endl;
    cout << "Fifth score at index 4: " << test_scores[4] << endl << endl;
    cout << "=============================================" << endl; 
    cout << endl; 

    cout << "\nEnter 5 test scores: ";
    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cin >> test_scores[3];
    cin >> test_scores[4];
    
    cout << "\nThe updated array is:" << endl;
    cout << "First score at index 0: " << test_scores[0] << endl;
    cout << "Second score at index 1: " << test_scores[1] << endl;
    cout << "Third score at index 2:  " << test_scores[2] << endl;
    cout << "Fourth score at index 3: " << test_scores[3] << endl;
    cout << "Fifth score at index 4: " << test_scores[4] << endl << endl;
    cout << "=============================================" << endl; 
    cout << endl; 

    // notice: what does the name of the array refer to 
    cout << "Notice what the value of the array name is : " << test_scores << endl << endl;
    cout << "=============================================" << endl; 
    cout << endl; 
    return 0;
}

