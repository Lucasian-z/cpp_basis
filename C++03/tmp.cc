#include <iostream>
using namespace std;
class Singleton
{
private:
    Singleton()
    {
        cout << "这是默认构造函数" << endl;
    }
    ~Singleton()
    {
        cout << "这是析构函数" << endl;
    }
    static Singleton *single;

public:
    static Singleton* getsingle()
    {
        if(single == nullptr)
            single = new Singleton();
        return single;
    }
    static void destory()
    {
        if(single)
            delete single;
    }
};
Singleton * Singleton::single = nullptr;
int main(int argc, char *argv[])
{
    Singleton *p1 = Singleton::getsingle();
    Singleton *p2 = Singleton::getsingle();
    Singleton *p3 = Singleton::getsingle();
    cout << p1 << endl
         << p2 << endl
         << p3 << endl;
    p1->destory();
    return 0;
}