#include <iostream>
#include <memory>
using namespace std;
class Child;
class Parent
{
public:
    Parent() { cout << "Parent()" << endl; }
    ~Parent() { cout << "~Parent()" << endl; }
    shared_ptr<Child> _pChild;
};
class Child
{
public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }
    weak_ptr<Parent> _pParent;
};

int main(int argc, char *argv[])
{
    shared_ptr<Parent> pParent(new Parent);
    shared_ptr<Child> pChild(new Child);
    cout << "pParent's use count = " << pParent.use_count() << endl;
    cout << "pChild's use count = " << pChild.use_count() << endl;
    
    pParent->_pChild = pChild;
    pChild->_pParent = pParent;
    cout << "pParent's use count = " << pParent.use_count() << endl;
    cout << "pChild's use count = " << pChild.use_count() << endl;
    return 0;
}
