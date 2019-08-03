#include <iostream>
using namespace std;
class Figure
{
private:
    /* data */
public:
    virtual void display()const = 0;
    virtual double area() const = 0;
};

class Circle:public Figure
{
private:
    double _r;
public:
    Circle(double r)
    :Figure()
    ,_r(r)
    {
        cout << "Circle(double r)" << endl;
    }
    void display() const
    {
        cout << "circle";
    }
    double area() const
    {
        return 3.14159*_r*_r;
    }
};

class Square:public Figure
{
private:
    double _a;
public:
    Square(double x)
    :_a(x)
    {
        cout << "Square(double x)" << endl;
    }
    void display()const
    {
        cout << "square";
    }
    double area()const{
        return _a*_a;
    }
};

void func(Figure *fig)
{
    fig->display();
    cout << "的面积是：" << fig->area() << endl;
}

int main()
{
    Circle c(3.3);
    Square s(5.5);
    func(&c);
    func(&s);
    return 0;
}
