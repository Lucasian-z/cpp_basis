#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

void test0()
{
    vector<string> ivec;
    ifstream ifs;
    ifs.open("file");
    if(!ifs.good())
    {
        cout << "i file open error" << endl;
        return;
    }

    ofstream ofs;
    ofs.open("hh.txt");//, std::ios::app);
    if(!ofs.good())
    {
        cout << "o file open error" << endl;
        return;
    }
    string line;
    while(getline(ifs, line))
    {
        cout << line << endl;
        ivec.push_back(line);
    }
    
    for(auto const &item : ivec)
    {
        ofs << item << "\n";
    }
    ofs.close();
    ofs.open("hh.txt",std::ios::app);
    ofs << "this is a new line" << "\n";
    ifs.close();
    ofs.close();
}

void test1()
{
    fstream fs("file2");
    if(!fs.good())
    {
        cout << "file open error" << endl;
        return;
    }
    int num = 0;
    for(int i = 0; i < 10; ++i)
    {
        cin >> num;
        fs << num << " ";
    }

    //cout << fs.tellp() << endl;
    //fs.seekg(std::ios::beg);
    while(fs >> num)
    {
        cout << num << " ";
    }
    cout << endl;
    fs.close();
}

void test3()
{
    ifstream ifs("file",std::ios::ate);
    if(!ifs.good())
    {
        cout << "file open error" << endl;
        return ;
    }
    cout << ifs.tellg() << endl;
    int length = ifs.tellg();
    char *buf = new char[length+1];
    ifs.seekg(std::ios::beg);
    ifs.read(buf, length);
    string str(buf);
    cout << str << endl;
    ifs.close();
}

int main(int argc, char *argv[])
{
    //test0();
    //test1();
    test3();
    return 0;
}