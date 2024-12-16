#include <iostream>
#include <iterator>
#include <vector>

using namespace std; 

int main () {
    
    vector<string> planets = {"Mercury", "Venus", "Earth", "Mars", "Neptune"}; 

    int array[6]{1,2,3,4,5,6}; 

    // for(int i = 0; i < planets.size(); i++) {
    //     cout << planets[i] << endl; 
    // }

    /// ranged based for loops 

    for(auto element : array) {
        cout << element << endl; 
    }

    for(vector<string>::iterator it = planets.begin(); it != planets.end(); ++it)
        cout <<*it << endl; 


    return 0; 
}