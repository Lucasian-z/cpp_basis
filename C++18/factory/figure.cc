#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

class Figure
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Figure() { cout << "~Figure()" << endl; }
};

void display(Figure *fig)
{
    fig->display();
    cout << "的面积是：" << fig->area() << endl;
}

class Rectangle:public Figure
{
public: 
    Rectangle(double length, double width)
    :_length(length)
    ,_width(width)
    {
        cout <<"Rectangle()" << endl;
    }
    void display()const
    {
        cout << "rectangle";
    }
    double area()const
    {
        return _length*_width;
    }
private:
    double _length;
    double _width;
};

class Circle : public Figure
{
public:
    Circle(double r)
    :_r(r)
    {
        cout << "Circle()" << endl;
    }
    void display() const
    {
        cout << "circle";
    }
    double area() const
    {
        return 3.14159*_r*_r;
    }
private:
    double _r;
};

class Factory
{
public:
    virtual Figure *create() = 0;
    virtual ~Factory() { cout << "~Factory()" << endl; }

};
class RectangleFactory:public Factory
{
public:
    Figure *create()
    {
        return new Rectangle(2,2);
    }
};

class CircleFactory:public Factory
{
public:
    Figure *create()
    {
        return new Circle(3.4);
    }
};

int main(int argc, char *argv[])
{
    unique_ptr<Factory> rectangleFactory(new RectangleFactory());
    unique_ptr<Figure> rectangle(rectangleFactory->create());
    unique_ptr<Factory> circleFactory(new CircleFactory());
    unique_ptr<Figure> circle(circleFactory->create());

    display(rectangle.get());
    display(circle.get());

    return 0;
}