#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace std;

// Custom Exception Class
class FileIOException : public runtime_error {
public:
    FileIOException(const string& message) : runtime_error(message) {}
};

// Template Class for Records
template <typename T>
class Record {
private:
    T id;
    string name;
    float score;

public:
    // Default and Parameterized Constructor
    Record() : id{}, name(""), score(0.0f) {}
    Record(T id, string name, float score) : id(id), name(name), score{score} {}

    // Friend Function for Less Than Operator
    friend bool operator<(const Record& lhs, const Record& rhs) {
        return lhs.score < rhs.score;
    }

    // Overloaded Output Stream Operator
    friend ostream& operator<<(ostream& os, const Record& record) {
        os << "ID: " << record.id << ", Name: " << record.name << ", Score: " << record.score << '\n';
        return os;
    }

    // Getter for Score
    float getScore() const {
        return this->score;
    }

    // Save Record to File
    void saveToFile(ofstream& file) const {
        if (!file.is_open()) {
            throw FileIOException("Error: Unable to open file for writing.");
        }
        file << id << " " << name << " " << score << "\n";
    }
};

// Function to Load Records from File
template <typename T>
vector<Record<T>> loadRecordsFromFile(const string& filename) {
    vector<Record<T>> records;
    ifstream file(filename);
    if (!file) {
        throw FileIOException("Error: Unable to open file for reading.");
    }

    T id;
    string name;
    float score;
    while (file >> id >> name >> score) {
        records.emplace_back(id, name, score);
    }

    return records;
}

int main() {
    vector<Record<int>> students; // Vector of student records
    string filename = "students.txt";
    char choice;

    try {
        while (true) {
            cout << "\n--- Student Management System ---\n";
            cout << "1. Add Student Record\n2. Save Records to File\n3. Load Records from File\n";
            cout << "4. Display All Records\n5. Compare Two Records (by score)\n6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == '1') {
                int id;
                string name;
                float score;

                cout << "Enter ID: ";
                if (!(cin >> id)) throw invalid_argument("Invalid ID input!");

                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Score: ";
                if (!(cin >> score)) throw invalid_argument("Invalid Score input!");

                students.emplace_back(id, name, score);
                cout << "Record Added Successfully!\n";
            }
            else if (choice == '2') {
                ofstream outFile(filename);
                for (const auto& student : students) student.saveToFile(outFile);
                cout << "Records saved to file.\n";
            }
            else if (choice == '3') {
                students = loadRecordsFromFile<int>(filename);
                cout << "Records loaded successfully.\n";
            }
            else if (choice == '4') {
                for (const auto& student : students) cout << student;
            }
            else if (choice == '5') {
                if (students.size() < 2) {
                    cout << "Not enough records to compare!\n";
                } else {
                    int i, j;
                    cout << "Enter index of first record: "; cin >> i;
                    cout << "Enter index of second record: "; cin >> j;
                    if (students[i] < students[j])
                        cout << "Record " << i << " has a lower score.\n";
                    else
                        cout << "Record " << j << " has a lower score.\n";
                }
            }
            else if (choice == '6') {
                cout << "Exiting Program. Goodbye!\n";
                break;
            }
            else {
                cout << "Invalid choice. Try again!\n";
            }
        }
    } catch (const FileIOException& e) {
        cerr << "File Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
