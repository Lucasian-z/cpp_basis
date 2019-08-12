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
    shared_ptr<Point> p1(new Point(2,2));
    p1->print();
    (*p1).print();
    cout << "p1's use count = " << p1.use_count() << endl;
    shared_ptr<Point> p2(p1);
    cout << "p1's use count = " << p1.use_count() << endl;
    cout << "p2's use count = " << p2.use_count() << endl;
    p2->print();
    (*p2).print();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}