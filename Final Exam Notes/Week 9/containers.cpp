#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

/* === Container Notes ===
- sequence containers: arrays, vectors, lists, forward_list, deque
- associative containers: set, multi set, map, multi map
- container adapter: stack, queue, prioity queue
- can store any primitive type in containers
*/

int main() {
    // 1. Vector: Dynamic array with fast access and slow insertions/removals.
    std::cout << "=== Vector Example ===\n";
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Add element to the end
    vec.push_back(7);
    std::cout << "Vector after push_back: ";
    for (int num : vec) std::cout << num << " ";
    std::cout << "\n\n";

    // 2. List: Doubly linked list with fast insertions/removals but slow access.
    std::cout << "=== List Example ===\n";
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_front(0);  // Insert at the front
    lst.push_back(6);    // Insert at the back
    std::cout << "List after push_front and push_back: ";
    for (int num : lst) std::cout << num << " ";
    std::cout << "\n\n";

    // 3. Deque: Double-ended queue with fast access and insertions/removals at both ends.
    std::cout << "=== Deque Example ===\n";
    std::deque<int> deq = {1, 2, 3, 4, 5};
    deq.push_front(0);  // Insert at the front
    deq.push_back(6);    // Insert at the back
    std::cout << "Deque after push_front and push_back: ";
    for (int num : deq) std::cout << num << " ";
    std::cout << "\n\n";

    // 4. Set: Collection of unique elements with automatic sorting.
    std::cout << "=== Set Example ===\n";
    std::set<int> st = {1, 2, 3, 4, 5};
    st.insert(3); // Duplicate will be ignored
    st.insert(6); // Insert new element
    std::cout << "Set after insert: ";
    for (int num : st) std::cout << num << " ";
    std::cout << "\n\n";

    // 5. Map: Collection of key-value pairs with automatic sorting based on the key.
    std::cout << "=== Map Example ===\n";
    std::map<int, std::string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";
    m[4] = "Four";
    m[2] = "Updated Two";  // Update value for key 2

    std::cout << "Map after insert and update: ";
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << "\n\n";

    return 0;
}
