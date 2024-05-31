#include <iostream>
#include <string>
#include <math.h>

struct BoundingBoxDimensions
{
    double width = 0;
    double height = 0;
};

class Shape
{
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;

public:
    void printParams(Shape *shape)
    {
        std::cout << "Type: " << shape->type()
                  << "\nSquare: " << shape->square()
                  << "\nWidth: " << shape->dimensions().width
                  << "\nHeight: " << shape->dimensions().height
                  << std::endl;
    }
};
class Triangle : public Shape
{
    double a, b, c;
    double p = (a + b + c) / 2;
    double square() override
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    BoundingBoxDimensions dimensions() override
    {
        double circumscribedCircleRadius = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
        BoundingBoxDimensions temp;
        temp.height = circumscribedCircleRadius * 2;
        temp.width = temp.height;
        return temp;
    }
    std::string type() override
    {
        return "Triangle";
    }

public:
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};
class Rectangle : public Shape
{
    double width = 0;
    double height = 0;
    double square() override
    {
        return width * height;
    }
    BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions temp;
        temp.height = height;
        temp.width = width;
        return temp;
    }
    std::string type() override
    {
        return "Rectangle";
    }

public:
    Rectangle(double _width, double _height) : width(_width), height(_height) {}
};
class Circle : public Shape
{
    double radius;
    double square() override
    {
        return atan(1) * 4 * radius;
    }
    BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions temp;
        temp.height = radius * 2;
        temp.width = temp.height;
        return temp;
    }
    std::string type() override
    {
        return "Circle";
    }

public:
    Circle(double _radius) : radius(_radius) {}
};

int main()
{
    Triangle t(3.0, 4.0, 5.0);
    t.printParams(&t);
    Rectangle r(4.0, 5.0);
    r.printParams(&r);
    Circle c(4.0);
    c.printParams(&c);
}