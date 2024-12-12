#include <iostream>
#include <string>
#include <type_traits>

class Player {
private:
    std::string name;
    int health;

public:
    Player() = default;
    Player(std::string name, int health) : name(name), health(health) {}
    Player(std::string name) : name(name), health(0) {}

    int getHealth() const {
        return this->health;
    }
    std::string getName() const {
        return this->name;
    }

    // Declare the generic swap template as a friend
    template <typename T>
    friend void swap(T &a, T &b);
};

// Generic swap template
template <typename T>
void swap(T &a, T &b) {
    if constexpr (std::is_same_v<T, Player>) {
        // Specialized logic for Player objects
        int temp = a.health;
        a.health = b.health;
        b.health = temp;
    } else {
        // Generic swap logic for other types
        T temp = a;
        a = b;
        b = temp;
    }
}

// Display template function
template <typename T1, typename T2>
void display(const T1 &a, const T2 &b) {
    std::cout << a << " " << b << "." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << p.getName();
    return os;
}

int main() {
    Player player1{"Player1", 90};
    Player player2{"Player2", 10};

    std::cout << "---Testing the display function template---" << std::endl;
    display(player1, "is winning"); // Output: Player1 is winning.

    std::cout << "---Swapping players---" << std::endl;
    swap(player1, player2);
    std::cout << player1.getName() << " has " << player1.getHealth() << " health points" << std::endl;
    // Output: Player1 has 10 health points

    return 0;
}
