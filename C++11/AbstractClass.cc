#include <iostream>
using namespace std;

class Parent
{
private:
    int _pid;
protected:
    Parent(int x)
    :_pid(x)
    {
        cout << "Parent()" << endl;
    }
public:
    virtual void display() const
    {
        cout << "pid = " << _pid << endl;
    }
};

class Son:public Parent
{
private:
    int _sid;
public:
    Son(int x1, int x2)
    :Parent(x1)
    ,_sid(x2)
    {
        cout << "Son(int x1, int x2)" << endl;
    }   
    virtual void display()const
    {
        cout << "Son = " << _sid << endl;
    }
};

void test()
{
    Son s(333,555);
    Parent *p = &s;
    p->Parent::display();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}