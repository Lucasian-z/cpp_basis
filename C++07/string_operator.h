#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class String
{
public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    void print()
    {
        cout << _str << endl;
    }
    String &operator=(const String& s);
    String &operator=(const char *);

    String &operator+=(const String&);
    String &operator+=(const char *);

    char *operator[](std::size_t index);
    const char &operator[](std::size_t index) const;

    std::size_t size() const;
    const char *c_str() const;

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, const String &s);

private:
    char *_str;
};