/*
 * This program shows some simple experiments with pointers and references.  
 */
#include <iostream>
using namespace std;

int main() {

	int aVal(100);
	// A Reference
	int& refAVal(aVal);
	cout << "aVal is " << aVal << endl;
	aVal = 500;
	cout << "aVal is now " << refAVal << " as seen through reference." << endl;
	refAVal = 2000;
	cout << "aVal is now " << aVal << " as assigned through reference." << endl;
	cout << "Memory use seen via reference: " << sizeof(refAVal) << "bytes" << endl;
	// But is this the size of the reference or the size of aVal?
	long double ldVar(1.0);
	long double& refLdVar(ldVar);
	cout << "Memory use seen via long double reference: " << sizeof(refLdVar) << "bytes" << endl;

	// A Pointer, declared in three equivalent ways:
	int* ptrAVal(&aVal);	
	//int *prtAVal(&aVal);
	//int* ptrAVal(&refAVal);

	cout << "\naVal is " << aVal << endl;
	cout << "ptrAVal is " << ptrAVal << endl;

	// De-referencing. Also called "indirection":
	*ptrAVal = 200;
	cout << "\naVal is " << aVal << endl;
	cout << "aVal is " << *ptrAVal << endl;
	cout << "ptrAVal is " << ptrAVal << endl;

	// Some simple pointer arithmetic:
	int* above(ptrAVal + 1);
	int* below(ptrAVal - 1);
	cout << "\nAbove aVal:\n";
	cout << "Pointer: " << above << endl;
	cout << "Value: " << *above << endl;
	cout << "\nBelow aVal:\n";
	cout << "Pointer: " << below << endl;
	cout << "Value: " << *below << endl;

	// Can I change the value stored above aVal?
	*above = 1000;
	cout << "\nAbove aVal again:\n";
	cout << "Pointer: " << above << endl;
	cout << "Value: " << *above << endl;

	// This causes a problem!  Why?
	// int* wayOut(ptrAVal + 1000);
	// cout << "\nPointer way above aVal: " << wayOut << endl;
	// cout << "Dereference: " << *wayOut << endl;
	// *wayOut = 100000;

	// How much memory is used to store a pointer and where is it stored?
	cout << "\nSize of ptrAVal: " << sizeof(ptrAVal) << endl;
	cout << "Size of pointer, again: " << sizeof(int*) << endl;
	cout << "ptrAVal stored at: " << &ptrAVal << endl;
	long double* ptrLdVar(&ldVar);
	cout << "Size of long double pointer: " << sizeof(ptrLdVar) << endl;
	cout << "Size of any pointer (void*): " << sizeof(void*) << endl;

	//int* notInitPtr;
	//cout << "\nUnitialized pointer: " << notInitPtr << endl;
//	cout << "De-referenced: " << *notInitPtr << endl;

	int* nullPointer(NULL);
	int* nullPointer1(nullptr);	// Better to use this with C++11 and newer
	cout << "\nA null pointer: " << nullPointer << endl;
	cout << "A null pointer: " << nullPointer1 << endl;
	// cout << *nullPointer1 << endl;

	return 0;
}
