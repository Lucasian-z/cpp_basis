#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    auto i = str.end();
    while (*i != '+' && *i != '-')
    {
        --i;
    }
    string str1 = str[0]=='+'?str.substr(1,i-str.begin()-2):str.substr(0, i-str.begin()-1);
    string str2 = str.substr(i-str.begin());
    cout << str1 << " " << str2 << endl;
    if(str1[0]=='-')
        str1.erase(str1.begin()+2);
    else
        str1.erase(str1.begin()+1);
    cout << "str1 = " << str1 << " " << "str2 = "<< str2 << endl;
    if(stoi(str2) < 0)
    {
        printf("hello");
        if(str1[0] == '-')
        {
            str1.insert(str1.begin()+1,stoi(str2.substr(1)), '0');
            str1.insert(str1.begin()+2, '.');
        }
            
        else
        {
            str1.insert(str1.begin(),stoi(str2.substr(1)), '0');
            str1.insert(str1.begin()+stoi(str2.substr(1)), '.');
        }
            
        
    }
    else
    {
        printf("hhh");
        if(str1[0] == '-')
        {
            printf("hhh");
            if(stoi(str2.substr(1))-str1.size()+2 >= 0)
                str1.insert(str1.end(),stoi(str2.substr(1))-str1.size()+2, '0');
            if(stoi(str2.substr(1)) < (str1.size()-3))
            {    printf("hhh\n");
                str1.insert(str1.begin()+stoi(str2.substr(1))+2, '.');}
        }
            
        else
        {
            str1.insert(str1.end(),stoi(str2.substr(1))-str1.size()+1, '0');
            if(stoi(str2.substr(1)) < str1.size()-2)
                str1.insert(str1.begin()+stoi(str2.substr(1))+1, '.');
        }
        
    }
    cout << str1 << endl;
    return 0;
}