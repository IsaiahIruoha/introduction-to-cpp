#include <iostream>
#include <iterator>
#include <vector>

using namespace std; 

int main () {
    
    vector<string> planets = {"Mercury", "Venus", "Earth", "Mars", "Neptune"}; 

    // for(int i = 0; i < planets.size(); i++) {
    //     cout << planets[i] << endl; 
    // }

    /// ranged based for loops 

    for(vector<string>::iterator it = planets.begin(); it != planets.end(); ++it)
        cout <<*it << endl; 


    return 0; 
}