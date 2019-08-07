#include <cstring>
#include <iostream>
using namespace std;

class HeapPerson
{
public:
    HeapPerson();
    HeapPerson(const char *name_str, const int num);
    void destory();
    void print();
    void *operator new(size_t sz);
    void operator delete(void *p);
private:
    ~HeapPerson();
    char *name;
    int ID;
};

void HeapPerson::operator delete(void *p)
{
    cout << "operator delete" << endl;
    free(p);
}

void *HeapPerson::operator new(size_t sz)
{
    cout << "operator new" << endl;
    void *ret = malloc(sz);
    return ret;
}

void HeapPerson::print()
{
    cout << "name: " << name << endl
         << "ID: " << ID << endl;
}

void HeapPerson::destory()
{
    if(this)
        delete this;
}

HeapPerson::~HeapPerson()
{
    cout << "这是析构函数" << endl;
    if(name)
        delete name;
}

HeapPerson::HeapPerson(const char *name_str, const int num)
:name(new char[strlen(name_str)+1]())
,ID(num)
{
    cout << "这是有参构造函数" << endl;
    strcpy(name, name_str);
}


int main(int argc, char *argv[])
{
    HeapPerson *p1 = new HeapPerson("lifangfei", 102);
    p1->print();
    p1->destory();
    return 0;
}