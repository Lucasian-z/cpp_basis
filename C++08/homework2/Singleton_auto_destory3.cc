#include <cstdlib>
#include <pthread.h>
#include <iostream>
using namespace std;
class Singleton
{
public:
    static Singleton *getinstance()
    {
        pthread_once(&_once, init);
        return _pinstance;
    }
    static void init()
    {
        atexit(destory);
        if(_pinstance == nullptr)
            _pinstance = new Singleton();
        
    }
    static void destory()
    {
        if(_pinstance)
            delete _pinstance;
    }
private:
    Singleton(){ cout << "Singleton()" << endl; }
    ~Singleton(){ cout << "~Singleton()" << endl; }
    static Singleton *_pinstance;
    static pthread_once_t _once;
};

Singleton *Singleton::_pinstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(int argc, char *argv[])
{
    Singleton *p1 = Singleton::getinstance();
    Singleton *p2 = Singleton::getinstance();
    cout << p1 << endl << p2 << endl;
    return 0;
}