#include <iostream>
#include <pthread.h>
using namespace std;

template<class T>
class Singleton
{
public:
    static T* getinstance()
    {
        pthread_once(&_once, init);
        return _pinstance;
    }
    static void init()
    {
        _pinstance = new T();
        atexit(destory);
    }
    static void destory()
    {
        if(_pinstance)
            delete _pinstance;

    }
private:
    Singleton(){cout << "Singleton()" << endl;}
    ~Singleton(){cout << "~Singleton()" << endl;}
private:
    static T* _pinstance;
    static pthread_once_t _once;
};

template<class T>
T *Singleton<T>::_pinstance = nullptr;
template<class T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

class Point
{
private:
    int _ix;
    int _iy;
public:
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }
    ~Point(){
        cout << "~Point()" << endl;
    }
};

int main(int argc, char* argv[])
{
    Point *p = Singleton<Point>::getinstance();
    Point *p1 = Singleton<Point>::getinstance();
    cout << p << endl
         << p1 << endl;
    return 0;
}