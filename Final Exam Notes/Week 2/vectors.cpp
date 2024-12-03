// week 2 vectors
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* === Vectors Notes === 
- Dynamic in side: can shrink or grow at runtime
- has same type elements 
- stored contiguously
- elements are automatically initialized to zero, unless stated otherwise
*/

int main() {
    string name = "test"; 
    cout << name << endl ; 
    vector<char> alphabet; // empty vector
    // vector<char> alphabet(10);    // 10 elements initialized to zero 
    vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
    cout << "The first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl << endl; 
    cout << "==================================================" << endl; 
    
    // no out of bounds checking 
    vector<int> quiz_scores {95, 88, 75};
    cout << "Quiz scores using array syntax []:" << endl;
    cout << quiz_scores[0] << endl;
    cout << quiz_scores[1] << endl;
    cout << quiz_scores[2] << endl << endl;
    cout << "==================================================" << endl; 

    // out of bounds checking 
    cout << "Quiz scores using vector syntax .at():" << endl;
    cout << quiz_scores.at(0) << endl;
    cout << quiz_scores.at(1) << endl;
    cout << quiz_scores.at(2) << endl;
    cout << "There are " << quiz_scores.size() << " scores in the vector" << endl << endl; 
    cout << "==================================================" << endl; 
    
    cout << "\nEnter 3 quiz scores: ";
    cin >> quiz_scores.at(0);
    cin >> quiz_scores.at(1);
    cin >> quiz_scores.at(2);
    cout << endl; 
    cout << "==================================================" << endl; 
    
    cout << "Updated quiz scores: " << endl;
    quiz_scores.pop_back(); 
    cout << quiz_scores.at(0) << endl;
    cout << quiz_scores.at(1) << endl << endl; 
    cout << "==================================================" << endl; 

    cout << "Enter a quiz score to add to the vector: ";
    int new_score {0};
    cin >> new_score;
    quiz_scores.push_back(new_score);
    
    cout << "\nEnter one more quiz score to add to the vector: ";
    cin >> new_score;
    quiz_scores.push_back(new_score);
    cout << "Quiz scores are now: " << endl;
    
    cout << quiz_scores.at(0) << endl;
    cout << quiz_scores.at(1) << endl;
    cout << quiz_scores.at(2) << endl;
    cout << quiz_scores.at(3) << endl;
    cout << quiz_scores.at(4) << endl;
    cout << "\nThere are now " << quiz_scores.size() << " scores in the vector" << endl << endl;
    cout << "==================================================" << endl; 

    // Example of a 2D-vector
    
    vector<vector<int>> song_ratings 
    {   
        {1, 2, 3, 4},
        {1, 2, 4, 4},
        {1, 3, 4, 5}
    };

    cout << "Here are the song ratings for reviewer #1 using array syntax:" << endl;
    cout << song_ratings[0][0] << endl;
    cout << song_ratings[0][1] << endl;
    cout << song_ratings[0][2] << endl;
    cout << song_ratings[0][3] << endl;
    
    cout << "Here are the song ratings for reviewer #1 using vector syntax:" << endl;
    cout << song_ratings.at(0).at(0) << endl;
    cout << song_ratings.at(0).at(1) << endl;
    cout << song_ratings.at(0).at(2) << endl;
    cout << song_ratings.at(0).at(3) << endl;
    
    cout << endl;
    return 0;
}
