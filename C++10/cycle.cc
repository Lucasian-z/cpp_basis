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

void test()
{
    Cycle c_example(5.4);
    c_example.show();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}