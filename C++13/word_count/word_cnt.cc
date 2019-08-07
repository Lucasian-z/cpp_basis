#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifs;
    map<string, int> imap;
    ifs.open("The_Holy_Bible.txt");
    if(!ifs.good())
    {
        cout << "file open error" << endl;
        return -1;
    }
    ofstream ofs;
    ofs.open("res.txt",std::ios_base::ate);
    if(!ofs.good())
    {
        cout << "result file open error" << endl;
        return -1;
    }
    string word;
    while(ifs >> word)
    {
        if(isalpha(word[0]))
        {
            while(!isalpha(word[word.size()-1]))
                word = word.substr(0, word.size()-1);//去掉字符串的最后一个字符
            ++imap[word];
        }
    }
    ifs.close();
    for(auto const &i : imap)
    {
        ofs << i.first << ": " << i.second << endl;
    }
    ofs.close();
    return 0;
}