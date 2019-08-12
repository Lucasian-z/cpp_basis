#include <iostream>
#include <memory>
using namespace std;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy){
        cout << "Point(int ix, int iy)" << endl;
    }
    void print(){
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
    ~Point(){
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test()
{
    weak_ptr<Point> wp;

    {
        shared_ptr<Point> sp(new Point(2,2));
        wp = sp;
        cout << "wp's use count = " << wp.use_count() << endl;
        cout << "sp's use count = " << sp.use_count() << endl;
        cout << "wp's expired = " << wp.expired() << endl;
        shared_ptr<Point> sp2 = wp.lock();
        if(sp2)
        {
            cout << "*sp2 = ";
            sp2->print();
            cout << "weak_ptr提升成功" << endl;
        }
        else
        {
            cout << "weak_ptr提升失败" << endl;
        }
    }
    cout << "wp's expired = " << wp.expired() << endl;
    cout << "wp's use count = " << wp.use_count() << endl;
    shared_ptr<Point> sp2 = wp.lock();
    if(sp2)
    {
        cout << "*sp2 = ";
        sp2->print();
        cout << "weak_ptr提升成功" << endl;
    }
    else
    {
        cout << "weak_ptr提升失败" << endl;
    }
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}