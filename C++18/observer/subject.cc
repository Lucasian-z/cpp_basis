#include "subject.h"
#include "observer.h"
#include <algorithm>
using namespace std;
void Ring::attach(Observer *obj)
{
    auto it = find(_obList.begin(), _obList.end(), obj);
    if(it == _obList.end())
    {
        _obList.push_front(obj);
    }
}

void Ring::detach(Observer *obj)
{
    auto it = find(_obList.begin(), _obList.end(), obj);
    if(it != _obList.end()) 
    {
        _obList.erase(it);
    }
}

void Ring::notify()
{
    for (auto &obj : _obList)
    {
        obj->update();
    }
}

void Ring::isPressed()
{
    if(!_isAlarming)
    {
        _isAlarming = true;
        notify();
    }
    _isAlarming = false;
}

void Guest::knock(Ring &ring)
{
    cout << ">>> Guest " << _name << " is knocking" << endl;
    ring.isPressed();
}