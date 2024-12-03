#include <iostream>
using namespace std; 

double getAverage(const int array[], int size) {
    if (size <= 0) {
        std::cerr << "Invalid array size\n";
        return -1; 
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return static_cast<double>(sum) / size;
}

double getMedian(int array[], int size) {
    if (size <= 0) {
        std::cerr << "Invalid array size\n";
        return -1; 
    }

    std::sort(array, array + size); // Sort the array part of the STL 

    if (size % 2 == 0) {
        return static_cast<double>(array[size / 2 - 1] + array[size / 2]) / 2;
    } else {
        return array[size / 2];
    }
}

void getAverageMedian (int array[], int size, double* average, double* median) {
    if (size <= 0) {
        std::cerr << "Invalid array size\n";
    }

    // average
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    *average = static_cast<double>(sum) / size;

    // median
    std::sort(array, array + size); // Sort the array part of the STL 
    if (size % 2 == 0) {
        *median = static_cast<double>(array[size / 2 - 1] + array[size / 2]) / 2;
    } else {
        *median = array[size / 2];
    }
}

void print (void* ptr, char type) {
    switch (type) {
        case 'i': 
            cout << *(static_cast <int*> (ptr)) << endl; 
            break; 
        case 'c': 
            cout << *(static_cast <char*> (ptr)) << endl; 
            break; 
        case 'd':
            cout << *(static_cast <double*> (ptr)) << endl; 
            break;
        default: 
            cout << "Error: invalid type. Please enter i, c or d" << endl; 
    }
}

int main (){
    // using the print function: printing any data type
    int num = 5; 
    char alphabet = 'e'; 
    print(&num, 'i'); 
    print(&alphabet, 'c'); 
    print(&alphabet, 'a'); 

    // // using getAverageMedian (returning more than one value)
    // double average {0.0}; 
    // double median {0.0}; 
    // int data [6] = {1, 2, 3, 4, 8, 6}; 
    // getAverageMedian (data, 6, &average, &median); 
    // cout << "The avergare is: " << average << " and the median is: " << median  << endl; 

    // // working with dynamic arrays 
    // int size; 
    // cout << "Input size of the array: "; 
    // cin >> size; 
    // // int array [size]; // not valid prior to C++11
    
    // int* dynamicData = new int[size]; 
    // cout << "==========input dynamic array============"<<endl; 
    // for (size_t i = 0; i < size; ++i) {
    //     cout << "dynamicData["<< i << "]: ";
    //     cin >> dynamicData[i];  
    // }
    // cout << "==========display dynamic array============"<<endl; 
    // for (size_t i = 0; i < size; ++i) { 
    //     cout << "dynamicData["<< i << "]: " << *(dynamicData + i) << endl; 
    // }
    // delete [] dynamicData; // deallocates memery that the array is pointing to 
    // dynamicData = nullptr; 

    // // multidiemntional dynamic arrays
    // int rows {0}, cols {0}; 
    // cout << "rows: "; 
    // cin >> rows; 
    // cout << "cols: "; 
    // cin >> cols; 

    // int** multiDimArray = new int* [rows]; 
    // for (size_t i = 0; i < rows; ++i) {
    //     multiDimArray[i] = new int [cols]; 
    // }

    // multiDimArray [1][2] = 7; 
    // cout << multiDimArray [1][3] << endl; 

    // // deleting
    // for (size_t i = 0; i < rows; ++i) {
    //     delete [] multiDimArray[i]; 
    // }
    // delete [] multiDimArray; 
    // multiDimArray = nullptr; 
    

 return 0; 
} 
