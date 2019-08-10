#include <iostream>
using namespace std;

template<class T>
class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease() {cout << "AutoRelease()" << endl;}
        ~AutoRelease(){
            if(_pinstance)
                delete _pinstance;
            cout << "~AutoRelease()" << endl;
        }
    };
public:
    template<class...Args>
    static T* getinstance(Args...args)
    {
        (void)_auto;
        if(_pinstance == nullptr)
            _pinstance = new T(args...);
        return _pinstance;
    }
private:
    Singleton(){cout << "Singleton()" << endl;}
    ~Singleton(){cout << "~Singleton()" << endl;}
private:
    static T* _pinstance;
    static AutoRelease _auto;
};

template<class T>
T *Singleton<T>::_pinstance = nullptr;

template<class T>
class Singleton<T>::AutoRelease Singleton<T>::_auto;

class Point
{
private:
    int _ix;
    int _iy;
public:
    Point(int ix, int iy)
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
    Point *p = Singleton<Point>::getinstance(1,2);
    Point *p1 = Singleton<Point>::getinstance(1,2);
    cout << p << endl
         << p1 << endl;
    return 0;
}