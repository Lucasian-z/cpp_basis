#include <iostream>
using namespace std;
class Base
{
public:
    Base() = default;
    Base(long base)
    :_base(base)
    {
        cout << "Base(long)" << endl;
    }
    void func1()
    {
        this->display();
    }
    void func2()
    {
        Base::display();
    }
    virtual void display() const
    {
        cout << "_base = " << _base << endl;
    }
protected:
    long _base;
};

class Derived
:public Base
{
public:
    Derived(long base, long derived)
    :Base(base)
    ,_derived(derived)
    {}
    void display() const override
    {
        cout << "_derived = " << _derived << endl;

    }
private:
    long _derived;
};

int main()
{
    Base base(1);
    Derived derived(11,12);
    base.func1();
    derived.func1();
    cout << endl;

    base.func2();
    derived.func2();
}