#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
// Function to calculate the score based on the answer key
int calculateScore(const string &answerKey, const string &response) {
    int score = 0;
    if (response.length() < answerKey.length()) {
        return -1;  // Incomplete response
    }
    for (int i = 0; i < answerKey.length(); ++i) {
        if (response[i] == answerKey[i]) {
            score++;
        }
    }
    return score;
}

int main() {
    ifstream inFile("QuizResponses.txt");
    ofstream outFile("QuizResults.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string answerKey;
    getline(inFile, answerKey);  // Read the answer key from the first line

    string employeeID, response;
    int lineNumber = 1;
    int totalScore = 0;
    int employeeCount {0};

    // Header for the table
    outFile << setw(30) << "Employee Quiz Responses" << endl;
    outFile << "Employee ID     Score     Redo Quiz" << endl;
    outFile << "------------------------------------" << endl;

    while (getline(inFile, employeeID)) {
        // Skip over blank lines between the employee ID and response
        while (employeeID.empty()) {
            getline(inFile, employeeID);
        }

        getline(inFile, response);
        
        // Handle potential blank lines before the response
        while (response.empty()) {
            getline(inFile, response);
        }

        // Calculate the score for the current employee
        int score = calculateScore(answerKey, response);
        bool redoQuiz = (score < 3 || score == -1); // if score is less than 3 or -1 then redo quiz

        // Output the result to the file
        outFile << lineNumber << setw(10) << employeeID 
                << setw(8) << score << "        "
                << left << setw(10) << (redoQuiz ? "yes" : "no") 
                << right << endl;

        if (score != -1) {
            totalScore += score;
        }
        employeeCount++;
        lineNumber++;
    }

    // Calculate and print the average score
    float averageScore = (totalScore) / employeeCount;
    outFile << "------------------------------------" << endl;
    outFile << "Average" << setw(13) << fixed << setprecision(2) << averageScore << endl;

    inFile.close();
    outFile.close();

    return 0;
}