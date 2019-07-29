#include "string_operator.h"

String::String()//默认构造函数
:_str(new char[1]())
{
}
String::String(const char *str)
:_str(new char[strlen(str)+1]())
{
    strcpy(_str, str);
}
String::String(const String& s)
:_str(new char[strlen(s._str)+1]())
{
    strcpy(_str, s._str);
}
String::~String()
{
    if(_str)
        delete []_str;
}
String & String::operator=(const String& s)
{
    if(this != &s)
    {
        free(_str);
        this->_str = new char[strlen(s._str)+1]();
        strcpy(_str, s._str);
    }
    return *this;
}
String &String::operator=(const char *s)
{
    bzero(_str, sizeof(_str));
    strcpy(_str, s);
    return *this;
}

String &String::operator+=(const String& s)
{
    String tmp = _str;
    _str = new char[strlen(_str)+strlen(s._str)+1]();
    strcpy(_str,tmp._str);
    strcat(_str,s._str);
    return *this;
}
String &String::operator+=(const char *s)
{
    String tmp = _str;
    _str = new char[strlen(_str)+strlen(s)+1]();
    strcpy(_str,tmp._str);
    strcat(_str,s);
    return *this;
}

char *String::operator[](std::size_t index)
{
    if(index >= 0 && index < strlen(_str))
        return _str + index;
}
const char &String::operator[](std::size_t index) const//此函数只能被const对象调用
{
    if(index >= 0 && index < strlen(_str))
        return _str[index];
}

std::size_t String::size() const
{
    return strlen(_str);
}
const char *String::c_str() const
{
    return _str;
}

bool operator==(const String &lhs, const String &rhs)
{
    if(!strcmp(lhs._str, rhs._str))
        return true;
    return false;
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs._str, rhs._str) < 0;
}
bool operator>(const String &lhs, const String &rhs)
{
    return strcmp(lhs._str, rhs._str) > 0;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return strcmp(lhs._str, rhs._str) <= 0;
}
bool operator>=(const String &lhs, const String &rhs)
{
    return strcmp(lhs._str, rhs._str) >= 0;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._str;
    return os;
}
std::istream &operator>>(std::istream &is, const String &s)
{
    is >> s._str;
    return is;
}

String operator+(const String &lhs, const String &rhs)
{
    String tmp;
    tmp += lhs;
    tmp += rhs;
    return tmp;
}
String operator+(const String &lhs, const char *str)
{
    String tmp;
    tmp += lhs;
    tmp += str;
    return tmp;
}
String operator+(const char *str, const String &rhs)
{
    String tmp;
    tmp += str;
    tmp += rhs;
    return tmp;
}

void test()
{
    String s1;
    String s2("This is a test string.");
    String s3(s2);
    String s4 = s3;
    cout << s2 << endl << s3 << endl << s4 << endl;
    const String s5 = s3;
    cout << *s2[3] << endl;
    cout << s5[3] << endl;
    cout << s5+s3 << endl;
    cout << s5+" hello,world" << endl;
    cout << (s5>s3) << endl;
    cout << (s5<=s3) << endl;
    cout << (s5==s3) << endl;
    cout << (s5!=s3) << endl;
    String s6;
    cin >> s6;
    cout << (s6 + s5) << endl;
    s6 += s5;
    cout << s6 << endl;
    cout << "hello,world " + s6 << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}