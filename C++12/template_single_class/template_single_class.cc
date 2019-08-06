#include "template_single_class.hpp"

void test()
{
    Point *p1 = Singleton<Point>::getInstance(1,2);
    Point *p2 = Singleton<Point>::getInstance(1,2);
    p2->print();
    cout << p1 << " " << p2 << endl;
    //Singleton<Point>* p = (Singleton<Point>*)p1;//将Point类进行强制转换
    //p->destory();
    ((Singleton<Point>*)p1)->destory();//销毁单例对象

    Computer *p3 = Singleton<Computer>::getInstance("lenovo", 5768);
    Computer *p4 = Singleton<Computer>::getInstance("lenovo", 5768);
    p3->print();
    cout << p3 << " " << p4 << endl;
    ((Singleton<Computer>*)p3)->destory();//销毁单例对象
}

int main(int argc, char *argv[])
{
    test();
    return  0;
}