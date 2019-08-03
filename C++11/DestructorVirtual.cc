#include <cstring>
#include <iostream>
using namespace std;

class Parent
{
private:
    char *_parent;
public:
    Parent(const char* parent)
    :_parent(new char[strlen(parent)+1]())
    {
        cout << "Parent(const char* parent)" << endl;
        strcpy(_parent, parent);
        cout << _parent << endl;
    }
    virtual void display() const
    {
        cout << "~Parent()" << endl;
    }
    virtual ~Parent()
    {
        cout << "~Parent()" << endl;
        if(_parent)
            delete []_parent;
    }
};

class Son : public Parent
{
private:
    char *_son;
public:
    Son(const char* son)
    :Parent(son)
    ,_son(new char[strlen(son)+1]())
    {
        cout << "Son(const char* son)" << endl;
        strcpy(_son, son);
        cout << _son << endl;
    }
    ~Son()
    {
        if(_son)
            delete []_son;
        cout << "~Son()" << endl;
    }
};

void test()
{
    
    Parent *p = new Son("hhhhh");
    delete p;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}