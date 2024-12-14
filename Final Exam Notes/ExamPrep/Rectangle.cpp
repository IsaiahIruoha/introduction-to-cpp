#include <iostream>

class Rectangle {
    private:
        float width, length; 

    public: 

    Rectangle() : width(1.0), length(1.0) {} 
    Rectangle(float W, float L) : width(W), length(L) {}

        float getWidth() const {
            return this->width; 
        }
        float getLength() const {
            return this->length; 
        }

        void setWidth(float W) {
            if (W > 0 ) 
                this->width = W;
            else
                this->width = 1.0; 
        }

        void setLength(float L) {
            if (L > 0 ) 
                this->length = L;
            else
                this->length = 1.0; 
        }

        float area() const {
            return this->width*this->length; 
        }

        float perimeter() const {
            return this->width*2+this->length*2; 
        }

        void display() const {
            std::cout << "The width is: " << this->getWidth() << " The length is: " << this->getLength() << std::endl; 
        }

        friend std::ostream &operator<<(std::ostream &os, const Rectangle& rect) {
            os << "Rectanlge Width" << rect.getWidth() << std::endl;
            return os; 
        }
}; 


int main() {
    Rectangle rect1; // Default constructor
    Rectangle rect2(4.5, 2.3); // Parameterized constructor

    // Display details of both rectangles
    rect1.display();
    rect2.display();

    // Modify rect1's dimensions
    rect1.setLength(10.0);
    rect1.setWidth(5.0);
    rect1.display();

    // Try setting an invalid width
    rect1.setWidth(-2.0); // Should reset to 1.0 and display a message
    rect1.display();

    return 0;
}
