#include <iostream>
using namespace std;
#pragma pack(push)
#pragma pack(1)
class Base
{
public:
    void display()const
    {
        cout << "Base::display()" << endl;
    }
    virtual void dispp() const
    {
        cout << "Base::virtual dispp()" << endl;
    }
};
class Son:public Base
{
private:
    int _a;
    double _b;
    char *c;
    short d;
public:
    virtual void dispp()const
    {
        cout << "Son::dispp()" << endl;
    }
};

int main(int argc, char *argv[])
{
    Base a;
    Son b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    return 0;
}