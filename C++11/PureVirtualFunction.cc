#include <iostream>
using namespace std;
class Base
{
public:
    virtual void display() = 0;
    virtual void print() = 0;
};
class Child1
:public Base
{
public:
    void display()
    {
        cout << "Child1::display()" << endl;
    }
};

class Child2
:public Child1
{
public:
    void print()override
    {
        cout << "Child2::print()" << endl;
    }
};
int main()
{
    Child2 child2;
    Base *pbase = &child2;
    pbase->print();
    pbase->display();
    return 0;
}