#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/* === Inheritance Notes ===
- inheritance is creating new classes from existing classes
- new child class has attributes (data) and methods (behaviour) of existing class
- avoids repition
- Single Inheritance: derived class extends one single base class
- Multiple Inheritance: class inherits from more than one base class
- Composition
    - Incorporating objects as attributes within another class to create more complex behaviors
    - "has-a " relationship (e.g., a car has-a engine)
- Access Modifiers
    - Public Inheritance ("is a" relationsip)
        - child class has public access to public, protected access to protected, no access to private
    - Protected Inheritance (not an "is a" relationsip)
        - child class has protected access to public, protected access to protected, no access to private
    - Private Inheritance (not an "is a" relationsip)
        - child class has private access to public, private access to protected, no access to private
- base class does not inherit base class constructor / destructor, overloaded assignment operators, friend functions
- copy constructor is not automatically inherited, can specifically invoke base clase copy constructor from derived class
*/

/* === Polymorphism Notes ===
- also known as late binding, functions are resolved at run time
- compiler adds code that identifies the kind of object at runtime then matches right call to right function def.
- declared using a virtual method
*/

const double PI = 3.14159265358979323846;

class Shape {
public:
    virtual double area() const { return 0.0; }
    virtual double perimeter() const { return 0.0; }
    virtual void displayProperties() const {
        std::cout << "Shape Properties: No specific properties for base shape.\n";
    }
    virtual ~Shape() {}
};

//rectangle class inherits from shape
class Rectangle : public Shape {
    double width, height;

    public:
        Rectangle(double width, double height) : width(width), height(height) {}

        double area() const override {return width*height;} //A = L*W
        double perimeter() const override {return 2*(width + height);} //P = 2*(L + W)

        void displayProperties() const override {
            std::cout << "Rectangle - Width: " << width
                  << ", Height: " << height
                  << ", Area: " << area()
                  << ", Perimeter: " << perimeter() << '\n';
        }
};

//circle class inherits from shape
class Circle : public Shape {
    double radius;

    public: 
        Circle(double radius) : radius(radius) {}

        double area() const override {return PI*radius*radius;} //A = pi*r^2
        double perimeter() const override {return 2*PI*radius;} //P = 2*pi*r

        void displayProperties() const override {
        std::cout << "Circle - Radius: " << radius
                  << ", Area: " << area()
                  << ", Circumference: " << perimeter() << '\n';
    }
};

//triangle class inherits from shape
class EquilateralTriangle : public Shape {
    double side;

    public: 
        EquilateralTriangle(double side) : side(side) {}

        double area() const override {return (sqrt(3) / 4)*side*side;}
        double perimeter() const override {return 3*side;}

    void displayProperties() const override {
        std::cout << "Equilateral Triangle - Side: " << side
                  << ", Area: " << area()
                  << ", Perimeter: " << perimeter() << '\n';
    }  
};

class GraphicsEditor {
    std::vector<Shape*> shapes;

    public:
        ~GraphicsEditor() {clearShapes();}

        void addShape(Shape* shape){
            shapes.push_back(shape);
        }

        void displayAllShapes() const {
            if(shapes.empty()){
                std::cout << "No shapes\n";
            }else{
                for(const auto&shape : shapes){
                    shape->displayProperties();
                }
            }
        }

        void displayLargestShape() const {
        if (shapes.empty()) {
            std::cout << "No shapes available to compare.\n";
            return;
        }
        auto largest = *std::max_element(shapes.begin(), shapes.end(),
            [](Shape* a, Shape* b) { return a->area() < b->area(); });
        largest->displayProperties();
    }

    double totalArea() const {
        double total = 0.0;
        for (const auto& shape : shapes) {
            total += shape->area();
        }
        return total;
    }

    void clearShapes() {
        for (auto& shape : shapes) {
            delete shape;
        }
        shapes.clear();
    }
};

int main() {
    GraphicsEditor editor;

    
    editor.addShape(new Rectangle(5, 10));
    editor.addShape(new Circle(7));
    editor.addShape(new EquilateralTriangle(6));

    
    std::cout << "Editor Shapes:\n";
    editor.displayAllShapes();

    
    std::cout << "\nShape with largest area:\n";
    editor.displayLargestShape();

    std::cout << "\nTotal area of all shapes: " << editor.totalArea() << std::endl;

    editor.clearShapes();
    std::cout << "\nShapes after clearing:\n";
    editor.displayAllShapes();

    return 0;
}
