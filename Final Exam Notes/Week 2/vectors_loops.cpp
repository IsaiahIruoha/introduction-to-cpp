#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// this example goes over the use of vector and the different types of loops
int main () {

	vector<int> data;
	unsigned int i;

	// Normal for loop
	for(i = 10; i <= 100; i += 10)
		data.push_back(i);

	// The .size() function returns an unsigned int, which make sense since
	// the size can never be negative, but this means that i should also be an
	// unsigned int in order to avoid any warnings.
	cout << "As assigned: ";
	for(i = 0; i < data.size(); i++)
		cout << data[i] << " ";
	cout << endl;

	// For-each loop from C++11 standard!
	cout << "Again using range based for loop: ";
	for(int j : data)		// Normal access
		cout << j << " ";
	cout << endl;

	// auto allows you to not have to explicitly provide the type of variable
	cout << "And again: using range based for loop and auto (type inference): ";
	for(auto j : data)		// Auto typing
		cout << j << " ";

	for(int j : data)		// Trying to change element of data
		j = 10 * j;
	cout << endl;
	
    cout << "Change attempt one:  ";
	for(auto j : data)
		cout << j << " ";

	for(int &j : data)		// By reference
		j = 10 * j;
	cout << endl;
	
    cout << "Change attempt two (by reference):  ";
	for(auto j : data)
		cout << j << " ";
	cout << endl;


	// for(const int &j : data)// By constant reference
	// 	j = 10 * j;
	// cout << endl;
	// for(auto j : data)
	// 	cout << j << " ";


// In bounds:
	cout << data.at(5) << endl;

	// Mutable
	data[5] = 1000;
	data.at(5) = 2000;
	cout << data[5] << endl;

	// Out of bounds:
	// Same behaviour as string class.
	// cout << data.at(50) << endl;
	// try {
	// 	cout << data.at(50) << endl;
	// } catch (out_of_range &e) {
	// 	cerr << "Error: " << e.what() << endl;
	// }

	// "Undefined" behaviour:
	cout << "\nWithout the try catch and using []:" << endl;
	cout << data[50] << endl;

	return 0;

}
