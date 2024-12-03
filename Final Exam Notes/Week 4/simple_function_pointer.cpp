#include <iostream>
#include <string>
using namespace std;

void showMessage(string);
void (*ptr_fcn)(string);

void showMessage(string s) {
	cout << s << endl;
}
int main() {

	ptr_fcn = showMessage;
	ptr_fcn("Hello!");

	// Alternately:
	ptr_fcn = &showMessage;
	(*ptr_fcn)("Hello again!");

	return 0;
}
