#pragma once
#include <iostream>
using namespace std;
class Line
{
public:
    Line();
    Line(int,int,int,int);
    ~Line();
    void printLine();
private:
    class LinePimpl;
    LinePimpl *_pimpl;
};