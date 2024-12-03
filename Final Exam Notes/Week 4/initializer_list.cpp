#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

void displayAll(const initializer_list<string>&);

void displayAll(const initializer_list<string>& collection) {
	cout << "list contains " << collection.size() << " elements." << endl;
	for(auto val : collection)
		cout << val << endl;
}

int main() {
	// Use an initializer list with standard container classes:
	vector<int> vInt{3, 4, 7, 9, -10, 1};
	vector<double> vDouble{7.5, 4.1, 7.6, 3e-4};
	vector<string> vString{"hello", "from", "376!"};

	// Supply an initializer list to a function
	displayAll({"hello", "from", "376!"});

	return 0;
}
