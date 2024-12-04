#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

/* === Iterators Notes ===
- process a sequence of elements of an arbitrary container
- iterator syntax is similar to that of pointers
- Input Iterators: read an element from the container
- Output Interators: write an element to the container
- Forward iterators: iterate forward one element at a time
- Bi-directional Iterators: like forward but in both directions
- Random Access Iterators: directly access a container element (e.g., using subscript operator [])
*/

int main() {
    // 1. Vector: Dynamic array with fast access and slow insertions/removals.
    std::cout << "=== Vector Example with Iterators ===\n";
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Add element to the end
    vec.push_back(7);
    
    // Using iterators to traverse the vector
    std::cout << "Vector using iterators: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // 2. List: Doubly linked list with fast insertions/removals but slow access.
    std::cout << "=== List Example with Iterators ===\n";
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_front(0);  // Insert at the front
    lst.push_back(6);    // Insert at the back
    
    // Using iterators to traverse the list
    std::cout << "List using iterators: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // 3. Deque: Double-ended queue with fast access and insertions/removals at both ends.
    std::cout << "=== Deque Example with Iterators ===\n";
    std::deque<int> deq = {1, 2, 3, 4, 5};
    deq.push_front(0);  // Insert at the front
    deq.push_back(6);    // Insert at the back
    
    // Using iterators to traverse the deque
    std::cout << "Deque using iterators: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // 4. Set: Collection of unique elements with automatic sorting.
    std::cout << "=== Set Example with Iterators ===\n";
    std::set<int> st = {1, 2, 3, 4, 5};
    st.insert(3); // Duplicate will be ignored
    st.insert(6); // Insert new element
    
    // Using iterators to traverse the set
    std::cout << "Set using iterators: ";
    for (std::set<int>::iterator it = st.begin(); it != st.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // 5. Map: Collection of key-value pairs with automatic sorting based on the key.
    std::cout << "=== Map Example with Iterators ===\n";
    std::map<int, std::string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";
    m[4] = "Four";
    m[2] = "Updated Two";  // Update value for key 2
    
    // Using iterators to traverse the map (key-value pairs)
    std::cout << "Map using iterators: ";
    for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << ": " << it->second << " ";
    }
    std::cout << "\n\n";

    return 0;
}
