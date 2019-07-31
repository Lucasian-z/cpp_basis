#include <iostream>
using namespace std;

class Singleton
{
    class autoRelease
    {
    public:
        autoRelease() { cout << "autoRelease()" << endl; }
        ~autoRelease() { 
            cout << "~autoRelease()" << endl; 
            if(_pinstance)
                delete _pinstance;
        }
    };
public:
    static Singleton *getinstance()
    {
        if(_pinstance == nullptr)
            _pinstance = new Singleton();
        return _pinstance;
    }
private:
    Singleton() { cout << "Sinleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }
    static autoRelease _auto;
    static Singleton *_pinstance;
};
Singleton *Singleton::_pinstance = nullptr;
Singleton::autoRelease Singleton::_auto;
int main(int argc, char *argv[])
{
    Singleton *p1 = Singleton::getinstance();
    Singleton *p2 = Singleton::getinstance();
    cout << p1 << endl << p2 << endl;
    return 0;
}