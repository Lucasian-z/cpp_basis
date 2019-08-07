#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

void test()
{
   
    //cout << "size:" << sizeof(ivec) << endl;
    int num = 0;
    while(cin >> num, !cin.eof())
    {
        if(cin.bad())
        {
            cout << "cin has corrected" << endl;
            return;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "input a valid interger:"<< endl;
            continue;
        }
        
        cout << num << " ";
        
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    test();
    
    return 0;
}