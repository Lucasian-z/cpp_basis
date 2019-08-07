#include <cstring>
#include <iostream>
using namespace std;

class StackPerson
{
public:
    StackPerson();
    StackPerson(const char *name_str, const int num);
    ~StackPerson();
    void print();
private:
    void* operator new(size_t sz);
    void operator delete(void *p);
    char *name;
    int ID;
};

void StackPerson::print()
{
    cout << "name: " << name << endl
         << "ID:" << ID << endl;
}

StackPerson::StackPerson()
{
    cout << "这是默认构造函数" << endl;
}

StackPerson::StackPerson(const char *name_str, const int num)
:name(new char[strlen(name_str)+1])
,ID(num)
{
    cout << "这是有参构造函数" << endl;
    strcpy(name, name_str);
}

StackPerson::~StackPerson()
{
    cout << "这是析构函数" << endl;
}

int main(int argc, char *argv[])
{
    StackPerson p("huailing", 101);
    p.print();
    
    return 0;
}