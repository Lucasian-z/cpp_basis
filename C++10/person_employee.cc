#include <iostream>
using namespace std;

class Person
{
private:
    string _name;
    int _age;
public:
    Person()
    {
        cout << "Person()" << endl;
    }
    Person(string name, int age)
    :_name(name)
    ,_age(age)
    {
        cout << "Person(string name, int age)" << endl;
    }
    void display()
    {
        cout << "name:" << _name << endl
             << "age:" << _age << endl;
    }
};

class Employee:public Person
{
private:
    string _department;
    double _salary;
public:
    Employee(string name, int age,string department, double salary)
    :Person(name, age)
    ,_department(department)
    ,_salary(salary)
    {
        cout << "Employment(string department, double salary)" << endl;
    }
    void display()
    {
        Person::display();
        cout << "department:" << _department << endl
             << "salary:" << _salary << endl;
    }
    double getSalary(){
        return _salary;
    }
};

void test()
{
    Employee e1("xiaoming", 22, "Finance", 9878.50);
    Employee e2("xiaohong", 23, "IT", 10023.78);
    Employee e3("xiaoai", 23, "Statistics", 8788);
    e1.display();
    e2.display();
    e3.display();
    cout << "average salary is:" << (e1.getSalary()+e2.getSalary()+e3.getSalary())/3 << endl;
    
}

int main(int argc, char *argvp[])
{
    test();
    return 0;
}