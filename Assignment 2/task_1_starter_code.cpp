// isaiah iruoha (20346489) 

#include <iostream>
#include <vector>
#include <cmath>

const double PI = 3.14159265358979323846;

// shape base class 
class Shape {
public:
    // virtual destructor so derived class destructors get called properly
    virtual ~Shape() {}

    // pure virtual function to enforce that derived classes implement these (think abstract)
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
};

// rectangle class 
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // constructor initializes width and height
    Rectangle(double w, double h) : width(w), height(h) {}

    // calculates and returns the area of the rectangle
    double area() const override {
        return width * height;
    }

    // calculates and returns the perimeter of the rectangle
    double perimeter() const override {
        return 2 * (width + height);
    }

    // displays the rectangle's properties
    void displayProperties() const override {
        std::cout << "Rectangle - Width: " << width << ", Height: " << height << ", Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
};

// circle class 
class Circle : public Shape {
private:
    double radius;

public:
    // constructor initializes the radius
    Circle(double r) : radius(r) {}

    // calculates and returns the area of the circle
    double area() const override {
        return PI * radius * radius;
    }

    // calculates and returns the perimeter (circumference) of the circle
    double perimeter() const override {
        return 2 * PI * radius;
    }

    // displays the circle's properties
    void displayProperties() const override {
        std::cout << "Circle - Radius: " << radius << ", Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
};

// equilateral triangle clas
class EquilateralTriangle : public Shape {
private:
    double side;

public:
    // constructor initializes the side length
    EquilateralTriangle(double s) : side(s) {}

    // calculates and returns the area of the equilateral triangle
    double area() const override {
        return (std::sqrt(3) / 4) * side * side;
    }

    // calculates and returns the perimeter of the equilateral triangle
    double perimeter() const override {
        return 3 * side;
    }

    // displays the triangle's properties like side length, area, and perimeter
    void displayProperties() const override {
        std::cout << "Equilateral Triangle - Side: " << side << ", Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
};

// graphic editor class 
class GraphicEditor {
private:
    std::vector<Shape*> shapes;

public:
    // default constructor
    GraphicEditor() = default;

    // destructor to clean up dynamically allocated shapes
    ~GraphicEditor() {
        clearShapes();
    }

    // adds a new shape to the collection
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    // displays all shapes in the collection
    void displayAllShapes() const {
        if (shapes.empty()) {
            return;
        }

        for (const auto& shape : shapes) {
            shape->displayProperties();
        }
    }

    // finds the shape with the largest area 
    Shape* largestShape() const {
        if (shapes.empty()) {
            return nullptr; // return nullptr if there are no shapes
        }

        // initialize a pointer to the first shape as the largest
        Shape* largest = shapes[0];

        // iterate through the shapes to find the one with the largest area
        for (size_t i = 1; i < shapes.size(); ++i) {
            if (shapes[i]->area() > largest->area()) {
                largest = shapes[i];
            }
        }
        return largest;
    }

    // displays the properties of the largest shape
    void displayLargestShape() const {
        Shape* largest = largestShape();
        if (largest) {
            largest->displayProperties();
        } else {
            std::cout << "No shapes available to determine the largest shape.\n\n";
        }
    }

    // calculates and returns the total area of all shapes in the collection
    double totalArea() const {
        double total = 0.0;
        for (const auto& shape : shapes) {
            total += shape->area();
        }
        return total;
    }

    // clears all shapes, deleting each dynamically allocated shape
    void clearShapes() {
        for (auto shape : shapes) {
            delete shape;
        }
        shapes.clear();
    }
};

// main function
int main() {
    GraphicEditor editor;

    // adding shapes
    editor.addShape(new Rectangle(5.0, 10.0));
    editor.addShape(new Circle(7.0));
    editor.addShape(new EquilateralTriangle(6.0));

    // display all shapes
    std::cout << "Editor Shapes:\n";
    editor.displayAllShapes();

    // display the largest shape
    std::cout << "\nShape with largest area:\n";
    editor.displayLargestShape();

    // display total area
    std::cout << "\nTotal area of all shapes: " << editor.totalArea() << std::endl << "\n";

    // clear all shapes
    editor.clearShapes();
    std::cout << "Shapes after clearing:\n";
    editor.displayAllShapes();

    return 0;
}
