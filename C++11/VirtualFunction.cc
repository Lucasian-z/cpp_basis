#include <iostream>
using namespace std;

class Base
{
private:
    int _age;
public:
    Base(int age)
    :_age(age)
    {
        cout << "Base()" << endl;
    }
    virtual void display(int x = 0) const
    {
        cout << "Base::x = " << x << endl;
    }
};

class Son : public Base
{
private:
    int _age;
public:
    Son(int age1, int age2)
    :Base(age1)
    ,_age(age2)
    {
        cout << "Son(int age1, int age2)" << endl;
    }
    virtual void display(int x = 1) const
    {
        cout << "Son::x = " << x << endl;
    }
};

int main()
{
    Son s(3,4);
    s.display();
    Base *pbase = &s;
    pbase->display();
    return 0;
}