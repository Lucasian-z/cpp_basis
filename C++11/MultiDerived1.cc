#include <iostream>
using namespace std;
class A
{
public:
    void print() const { cout << "A::print()"<< endl; }

};
class B
{
public:
    void print() const { cout << "B::print()"<< endl; }

};
class C
{
public:
    void print() const { cout << "C::print()"<< endl; }

};

class D:public A, public B, public C
{
public:
    D()
    :_ix(1)
    ,_iy(2)
    {

    }
private:
    int _ix;
    int _iy;
};

int main()
{
    D d;
    d.A::print();
    d.B::print();
    d.C::print();
    return 0;
}