#include "text_query.h"

void TextQuery::readFile(const string filename)//将文件内容存至容器中
{
    ifstream ifs;
    ifs.open(filename);
    if(!ifs.good())
    {
        cout << "file open error" << endl;
        return;
    }
    string str;
    while(getline(ifs, str))
    {
        ivec.push_back(str);
    }
    for(int i = 0; i < ivec.size(); ++i)
    {
        string word;
        for(auto const &j : ivec[i])
        {
            if(!isalpha(j))
            {
                imap[word].insert(i+1);
                word = "";
            }
            else
                word += j;
        }
    }
}

void TextQuery::query(const string &word)
{
    for(auto const &item : imap)
    {
        if(item.first == word)
        {
            cout << word << " occurs " << item.second.size() << " times" << endl;
            for(auto const &item2 : item.second)
            {
                cout << "(line " << item2 << ") " << ivec[item2-1] << endl;
            }
        }
    }
}