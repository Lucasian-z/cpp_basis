#include <iostream>
using namespace std;
const double pi = 3.14;
class Cycle
{
public:
    Cycle()
    :_r(0){
        cout << "Cycle()" << endl;
    }
    Cycle(double r)
    :_r(r){
        cout << "Cycle(double r)" << endl;
    }
    double getArea(){
        return pi*_r*_r;
    }
    double getPerimeter(){
        return 2*pi*_r;
    }
    void show(){
        cout << "r = " << _r << endl
             << "area = " << this->getArea() << endl
             << "perimeter = " << this->getPerimeter() << endl;
    }
private:
    double _r;
};

class Cylinder:public Cycle
{
public:
    Cylinder(double r, double h)
    :Cycle(r)
    ,_h(h){
        cout << "Cylinder(double r, double h)" << endl;
    }
    double getVolume(){
        return getArea()*_h;
    }
    void showVolume(){
        cout << "The volume of the cylinder is " << getVolume() << endl;
    }
private:
    double _h;
};

void test()
{
    Cylinder cylinder(3, 4);
    cylinder.showVolume();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}