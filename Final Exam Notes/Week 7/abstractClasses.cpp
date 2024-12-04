#include <iostream>
#include <string>

/* === Abstract Classes Notes ===
- cannot be instantiated
- serve as blueprints or templates for other classes to inherit from
- contain atleast one pure virtual function, marked with = 0
- if child of abstract class is not be to be virtual as well, then it must implement pure
  virtutal methods
- if a derived class does not implement a pure virtual method from the base class, it becomes
  abstract as well
*/

// Abstract base class: Shape
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double calculateArea() const = 0;

    // Pure virtual function to display shape information
    virtual void display() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        std::cout << "Circle with radius: " << radius
                  << ", Area: " << calculateArea() << std::endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }

    void display() const override {
        std::cout << "Rectangle with width: " << width
                  << ", height: " << height
                  << ", Area: " << calculateArea() << std::endl;
    }
};

int main() {
    // Shape* points to derived objects
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);

    // Demonstrating polymorphism
    circle->display();
    rectangle->display();

    // Clean up
    delete circle;
    delete rectangle;

    return 0;
}
