#include <iostream>
using namespace std;
class Grandpa
{
private:
    int _age;
public:
    Grandpa(int age)
    :_age(age)
    {
        cout << "Grandpa(int age)" << endl;
    }
    virtual void func1()
    {
        cout << "Grandpa::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Grandpa::func2()" << endl;
    }
    ~Grandpa()
    {
        cout << "~Grandpa()" << endl;
    }
};

class Son : public Grandpa
{
private:
    int _age;
public:
    Son(int age1, int age2)
    :Grandpa(age1)
    ,_age(age2)
    {
        cout << "Son(int age1, int age2)" << endl;
        func1();
    }
    void func1()
   {
       cout << "Son::func1()" << endl;
    }

    void func2()
   {
       cout << "Son::func2()" << endl;
   }
    ~Son()
    {
        cout << "~Son()" << endl;
        func2();
    }
};

class GrandSon : public Son
{
private:
    int _age;
public:
    GrandSon(int age1, int age2, int age3)
    :Son(age1, age2)
    ,_age(age3)
    {
        cout << "GrandSon(int age1, int age2, int age3)" << endl;

    }
    void func1(){
        cout << "GrandSon::func1()" << endl;
    }
    void func2(){
        cout << "GrandSon::func2()" << endl;
    }
    ~GrandSon(){
        cout << "~GrandSon()" << endl;
    }
};

int main()
{
    GrandSon(78,45,23);
    return 0;
}