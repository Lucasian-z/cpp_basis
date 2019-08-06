#pragma once
#include <iostream>
#include <string>
using namespace std;

//创建单例对象实现一个模板形式的单例类，
//要求对于任意类型的类经过Singleton的处理之后，
//都能获取一个单例对象，并且可以传递任意参数
template<class T>
class Singleton
{
private:
    static T* _pinstance;
    Singleton(){};
    ~Singleton(){};
public:
    template<class...Args>//传递任意个参数
    static T *getInstance(Args...args)
    {
        
        if(_pinstance == nullptr)
            _pinstance = new T(args...);
        return _pinstance;
    }
    static void destory()
    {
        if(_pinstance)
            delete _pinstance;
        //_pinstance = nullptr;
    }
};

template<class T>
T * Singleton<T>::_pinstance = nullptr;

class Point
{
private:
    int _ix;
    int _iy;
public:
    Point(){};
    Point(int x, int y = 22)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int x, int y)" << endl;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
    void print()
    {
        cout << "坐标为：(" << _ix << "," << _iy << ")" << endl;
    }
};

class Computer
{
private:
    string _brand;
    double _price;
public:
    Computer(string brand, double price)
    :_brand(brand)
    ,_price(price)
    {
        cout << "Computer(string brand, double price)" << endl;
    }
    ~Computer(){
        cout << "~Computer()" << endl;
    }
    void print()
    {
        cout << "brand:" << _brand << " price:" << _price << endl;
    }
};