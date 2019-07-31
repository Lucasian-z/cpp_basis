#include <iostream>
using namespace std;
class Singleton
{
public:
    static Singleton* getinstance()
    {
        if(_pinstance == nullptr)
        {
            atexit(destory);
            _pinstance = new Singleton();
        }
            
        return _pinstance;
    }   
    static void destory()
    {
        if(_pinstance)
            delete _pinstance;
    }
private:
    Singleton(){ cout << "Singleton()" << endl; }
    ~Singleton(){ cout << "~Singleton()" << endl; };
    static Singleton *_pinstance;
};
Singleton * Singleton::_pinstance = nullptr;

int main(int argc, char *argv[])
{
    Singleton *p1 = Singleton::getinstance();
    Singleton *p2 = Singleton::getinstance();
    cout << p1 << endl << p2 << endl;
    return 0;
}