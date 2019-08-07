#include <iostream>
using namespace std;
class singleton
{
private:
    singleton()
    {
        cout << "这是默认构造函数" << endl;
    };//默认构造函数
    singleton(const singleton &rhs);//默认拷贝构造函数
    ~singleton()
    {
        cout << "这是析构函数" << endl;
    }
    static singleton *single;

public:
    
    static singleton* getsingle()
    {
        if(single == nullptr)
        {
            single = new singleton();
            
        }
        return single;
    }
    static void destory()
    {
        if(single)
            delete single;
    }
};
singleton* singleton::single = nullptr;
int main(int argc, char *argv[])
{
    singleton *p1 = singleton::getsingle();
    singleton *p2 = singleton::getsingle();
    singleton *p3 = singleton::getsingle();
    singleton *p4 = singleton::getsingle();
    cout << p1 << endl
         << p2 << endl
         << p3 << endl
         << p4 << endl;
    p1->destory();

    return 0;
}