#include "Line.h"

class Line::LinePimpl
{
    //定义点类
    class Point
    {
    public:
        Point(int x,int y)
        : _ix(x), _iy(y)
        {
            cout << "Point::Point(int x, int y)" << endl;
        }
        ~Point()
        {
            cout << "Point::~Point()" << endl;
        }
        void printPoint()
        {
            cout << "(" << _ix << ", " << _iy << ")" << endl;
        }
    private:
        int _ix;
        int _iy;
    };
private:
    Point _pt1;
    Point _pt2;
public:
    LinePimpl(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1), _pt2(x2, y2)
    {
        cout << "LinePimpl::LinePimpl(int x1, int y1, int x2, int y2)" << endl;
    }
    ~LinePimpl()
    {
        cout << "LinePimpl::~LinePimpl()" << endl;
    }
    void printPimpl()
    {
        _pt1.printPoint();
        cout << "------>" << endl;
        _pt2.printPoint();
    }
};


Line::Line()
{
    cout << "Line::Line()" << endl;
}
Line::Line(int x1, int y1, int x2, int y2)
:_pimpl(new LinePimpl(x1,y1,x2,y2))
{
    cout << "Line::Line()" << endl;
}
Line::~Line()
{
    if(_pimpl)
        delete _pimpl;
    cout << "Line::~Line()" << endl;
}
void Line::printLine()
{
    _pimpl->printPimpl();
}