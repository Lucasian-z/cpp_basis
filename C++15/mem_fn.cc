#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Number
{
public:
    Number(int data)
        : _data(data) {}
    void display()
    {
        cout << _data << " ";
    }
    bool isEven() const
    {
        return _data % 2 == 0;
    }
    bool isPrime() const
    {
        if (_data == 0 || _data == 1)
            return false;
        for (int i = 2; i <= _data / 2; ++i)
            if (_data % i == 0)
                return false;
        return true;
    }

private:
    int _data;
};

int main(int argc, char *argv[])
{
    vector<Number>ivec;
    for(int i = 1; i != 100; ++i)
        ivec.emplace_back(i);
    // for_each(ivec.begin(), ivec.end(), mem_fn(&Number::display));
    // cout << endl;
    // auto it = remove_if(ivec.begin(), ivec.end(), mem_fn(&Number::isEven));
    // ivec.erase(it, ivec.end());
    // for_each(ivec.begin(), ivec.end(), mem_fn(&Number::display));
    // cout << endl;
    auto it = remove_if(ivec.begin(), ivec.end(), mem_fn(&Number::isPrime));
    ivec.erase(it, ivec.end());
    //for_each(it, ivec.end(), mem_fn(&Number::display));
    for_each(ivec.begin(), ivec.end(), mem_fn(&Number::display));
    cout << endl;
    return 0;

}