#include <iostream>
#include <stdexcept>
using namespace std;

double calculateAverage(const int grades[], int size);
int findHighestGrade(const int grades[], int size);
int findLowestGrade(const int grades[], int size); 
int countAboveAverage(const int grades[]. int size, double average); 

int main () {
    const int MAX_STUDENTS = 50; 
    int grades[MAX_STUDENTS];
    int numStudents;

    cout << "Enter num of students max 50" << endl;
    cin >> numStudents;
    
    try {
        if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
            cout << "Invalid num students" << endl; 
        } else {
            throw invalid_argument("Invalid num students");
        }
    }

    catch (const invalid_argument& e) {
        cout << "Invalid num students" << e.what() << endl;
    }

    // Step 2: Input grades
    cout << "Enter the grades of the students (0 to 100):" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Grade for student " << (i + 1) << ": ";
        cin >> grades[i];
        if (grades[i] < 0 || grades[i] > 100) {
            cout << "Invalid grade. Please enter a grade between 0 and 100." << endl;
            --i; // Retry the same student
        }
    }

    // Step 3: Calculate statistics
    double average = calculateAverage(grades, numStudents);
    int highest = findHighestGrade(grades, numStudents);
    int lowest = findLowestGrade(grades, numStudents);
    int aboveAverage = countAboveAverage(grades, numStudents, average);

    // Step 4: Display results
    cout << "\nClass Statistics:\n";
    cout << "Average grade: " << average << endl;
    cout << "Highest grade: " << highest << endl;
    cout << "Lowest grade: " << lowest << endl;
    cout << "Number of students above average: " << aboveAverage << endl;

    return 0;
    
}

double calculateAverage(const int grades[], int size) {
    double sum = 0; 
    for(int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return sum/size; 
}

int findHighestGrade(const int grades[], int size) {
    int max = grades[0];
    for (int i = 0; i < size; i++) {
        if (grades[)
    }
}

int findLowestGrade(const int grades[], int size) {

}

int countAboveAverage(const int grades[], int size, double average) {

}