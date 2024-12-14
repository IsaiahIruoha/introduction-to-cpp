#pragma once

#include <iostream>
#include <stdexcept>

class BadPoint : public std::runtime_error {
    public:
        explicit BadPoint(const std::string& message) : std::runtime_error(message) {}
}; 

class BadOutline : public std::runtime_error {
    public:
        explicit BadOutline(const std::string& message) : std::runtime_error(message) {}
};

class Point {
    private:
        float x, y; 
    
    public: 
        Point(float xVal, float yVal); 
        
        float getX() const;
        float getY() const; 
}; 

class Outline {
    private:
        Point** points; 
        int size; 

    public:
        Outline(const float xVals[], const float yVals[], int size); 

        Outline(const Outline& other); 
        Outline& operator=(const Outline& other); 
        ~Outline(); 

        Point getPoint(int index) const; 
        int getSize() const;
}; 
