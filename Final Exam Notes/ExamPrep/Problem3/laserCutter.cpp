#include <iostream>
#include "laserCutter.h"
#include <stdexcept>

// Constructor: Initializes x and y throws BadPoint if invalid
Point::Point(float xVal, float yVal) : x(xVal), y(yVal) {
    if (x < 0.0f || x > 200.0f || y < 0.0f || y > 200.0f) {
        throw BadPoint("Point: X or Y value out of bounds"); 
    }
}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y; 
}

Outline::Outline(const float xVals[], const float yVals[], int size) : size(size) {
    if (size < 2) {
        throw BadOutline("Outline: Size must be at least 2"); 
    }

    points = new Point*[size];
    for (int i = 0; i < size; ++i) {
        try {
            points[i] = new Point(xVals[i], yVals[i]); 
        } catch (const BadPoint& bp) {
            for (int j = 0; j < i; ++j) {
                delete points[j]; 
            }
            delete[] points; 
            throw; 
        }
    }

}

Outline::Outline(const Outline& other) : size(other.size) {
    points = new Point*[size]; 
    for (int i = 0; i < size; ++i) {
        points[i] = new Point(*other.points[i]); 
    }
}

Outline& Outline::operator=(const Outline& other) {
    if (this == &other) {
        return *this; 
    }

    for (int i = 0; i < size; ++i) {
        delete points[i]; 
    }
    delete[] points; 

    size = other.size; 
    points = new Point*[size]; 
    for (int i = 0; i < size; ++i) {
        points[i] = new Point(*other.points[i]);
    }

    return *this; 
}

Outline::~Outline() {
    for (int i = 0; i < size; ++i) {
        delete points[i]; 
    }
    delete [] points; 
}

Point Outline::getPoint(int index) const {
    if (index < 0 || index >= size) {
        throw BadOutline("Outline: Index out of bounds"); 
    }
    return *points[index]; 
}

int Outline::getSize() const {
    return size; 
}



void showPoint(Point p) {
    std::cout << "(" << p.getX() << ", " << p.getY() << ")" << std::endl;
} // end showPoint

void showOutline(Outline& out) {
    std::cout << "Contents of outline:" << std::endl;
    for (int i = 0; i < out.getSize(); i++) {
        showPoint(out.getPoint(i));
    }
} // end showOutline

int main() {
    Point p(5.0f, 6.0f);
    std::cout << "Legal Point: ";
    showPoint(p);
    std::cout << "Illegal Point: ";
    try {
        Point pBad(-10.0f, 300.0f);
    } catch (BadPoint& bp) {
        std::cout << bp.what() << std::endl;
    }

    float xVals[] = {2.0f, 4.0f, 4.0f, 1.0f};
    float yVals[] = {7.0f, 8.0f, 3.0f, 2.0f};

    Outline out(xVals, yVals, 4);
    std::cout << "Legal Outline: ";
    showOutline(out);
    std::cout << "Illegal Index: ";
    try {
        showPoint(out.getPoint(100));
    } catch (BadOutline& bo) {
        std::cout << bo.what() << std::endl;
    }

    std::cout << "Illegal Outline: ";
    try {
        Outline out(xVals, yVals, -10);
    } catch (BadOutline& bo) {
        std::cout << bo.what() << std::endl;
    }

    std::cout << "Another Illegal Outline: ";
    float yBadVals[] = {7.0f, -10.0f, 3.0f, 2.0f};
    try {
        Outline out(xVals, yBadVals, 4);
    } catch (BadPoint& bp) {
        std::cout << bp.what() << std::endl;
    } catch (BadOutline& bo) {
        std::cout << bo.what() << std::endl;
    }

    return 0;
}
