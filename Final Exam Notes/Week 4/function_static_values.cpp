#include <iostream>
using namespace std;

void testFunction();

void testFunction() {
	static int staticVal(0);
	int aVal(0);
	staticVal++;
	aVal++;
	cout << "staticVal = " << staticVal << ", aVal = " << aVal << endl;
}

int main() {
	testFunction();
	testFunction();
	testFunction();
	testFunction();
	// cout << staticVal << endl;	// staticVal is local to testFunction!

	return 0;
}



