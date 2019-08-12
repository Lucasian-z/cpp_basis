#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() { cout << "~Observer()" << endl; }

};

class Baby:public Observer
{
public:
    Baby(const string &name)
    :_name(name)
    {}
    void update()
    {
        srand(clock());
        int number = rand()%100;
        if(number < 70){
            cout << "Baby " << _name << " is sleeping" << endl;
        }else
        {
            cout << "Baby " << _name << " is crying" << endl;
        }
    }
private:
    string _name;
};

class Nurse : public Observer
{
public:
    Nurse(const string &name)
    :_name(name)
    {}
    void update()
    {
        srand(clock());
        int number = rand()%100;
        if(number < 70){
            cout << "Nurse " << _name << " is ready to open the door" << endl;
        }else
        {
            cout << "Nurse " << _name << " is sleeping" << endl;
        }     
    }
private:
    string _name;
};