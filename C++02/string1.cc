#include <iostream>
using namespace std;
class example
{
    public:
    example(int a)
    :x(a)
    ,y(x)
    {
        cout << "这是有参构造函数" << endl;
    }
    void print();
    ~example()
    {
        cout << "这是析构函数" << endl;
    }
    private:
    int y;
    int x;
};

void example::print()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
int main(int argc, char *argv[])
{
    example e(10);
    e.print();
    return 0;
}