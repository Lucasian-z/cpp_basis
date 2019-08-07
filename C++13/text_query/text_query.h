#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;
class TextQuery
{
public:
    void readFile(const string filename);
    void query(const string &word);
private:
    vector<string> ivec;
    map<string, set<int>> imap;
};