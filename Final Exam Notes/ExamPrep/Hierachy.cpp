#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
    virtual ~Parent() {} // Virtual destructor

    string fcnOne() {
        return "POne";
    }

    string fcnOne(string aVal) {
        return "POne " + aVal;
    }

    virtual string fcnTwo(string aVal) {
        return "PTwo " + aVal;
    }

    virtual string fcnThree(string aVal) = 0;

    virtual string fcnFour(string aVal = "hello") {
        return "PFour " + aVal;
    }
};

class Child : public Parent {
public:
    string fcnOne() {
        return "COne";
    }

    string fcnOne(string aVal, string bVal) {
        return "COne " + aVal + bVal;
    }

    string fcnTwo() {
        return "CTwo";
    }

    string fcnTwo(string aVal) override {
        return "CTwo " + aVal;
    }

    string fcnThree(string aVal) override {
        return "CThree " + aVal;
    }

    string fcnFour(string aVal = "goodbye") override {
        return "CFour " + aVal;
    }
};

class GrandChild : public Child {
public:
    string fcnFive() {
        return "GFive";
    }

    string fcnFive(string aVal) {
        return "GFive " + aVal;
    }
};


int main() {
    Parent p1;
    cout << p1.fcnOne() << endl;

    Child c1;
    cout << c1.fcnOne() << endl;
    cout << c1.fcnOne("10") << endl;
    cout << c1.fcnOne("20", "30") << endl;
    cout << c1.fcnTwo() << endl;
    cout << c1.fcnTwo("40") << endl;
    cout << c1.fcnThree("50") << endl;
    cout << c1.fcnFour() << endl;

    cout << "\nSecond part:" << endl;

    Parent* p2 = &c1;
    cout << p2->fcnOne() << endl;
    cout << p2->fcnOne("15") << endl;
    cout << p2->fcnTwo("45") << endl;
    cout << p2->fcnThree("55") << endl;
    cout << p2->fcnFour() << endl;

    cout << "\nThird part:" << endl;

    GrandChild gc;
    Child c2 = gc;
    cout << c2.fcnFive() << endl;
    cout << c2.fcnFive("100") << endl;

    return 0;
}
