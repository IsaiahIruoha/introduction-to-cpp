

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream inData;
    ofstream outData;

    string inVar1;
    string inVar2;


    cout << endl << "This program reads from an input file, file_input.txt,"
	 << endl << " and writes to an output file, file_output.txt" << endl;

    inData.open("input.txt");
    if (!inData)
       {
       cerr << "** Problem: cannot open file_input.txt, ending program."
	    << endl;
       return 1;
       }

    outData.open("output.txt");
    if (!outData)
       {
       cerr << "** Problem: cannot open file_output.txt, ending program."
	    << endl;
       return 1;
       }

    inData >> inVar1 >> inVar2;

    while ( inData)
       {
       outData << inVar2;     // output in reverse order
       outData << " ";
       outData << inVar1;     
       outData << endl;     

       inData >> inVar1 >> inVar2;

       } // end while
    
    inData.close();
    outData.close();

} // end main