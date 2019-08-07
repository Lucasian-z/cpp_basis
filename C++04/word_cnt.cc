#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//统计圣经中的词频，定义一个容器，其元素为结构体（单词，出现次数）
//打开圣经，并逐个读入单词，然后判断是否已在容器中，若已存在，则将
//对应的个数++，否则初始化一个临时结构体并加入容器
//创建一个存放结果的文件，依次把容器的内容写入文件
//关闭文件
struct Word_cnt
{
    string word;
    int cnt;
};

void func()
{
    vector<Word_cnt> ivec;
    string filename = "The_Holy_Bible.txt";
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.good())
    {
        cout << "1 file open error" << endl;
        return;
    }

    ofstream ofs;
    ofs.open("res.txt", std::ios_base::ate);
    if (!ofs.good())
    {
        cout << "2 file open error" << endl;
    }
    string word;
    Word_cnt tmp;
    int flag = 0;
    while (ifs >> word)
    {
        flag = 0;
        for (auto &item : ivec)
        {
            if (item.word == word)
            {
                item.cnt++;
                flag = 1;
                break;
            }
        }
        if (!flag && !(word[0] >= '0' && word[0] <= '9'))
        {
            tmp.word = word;
            tmp.cnt = 1;
            ivec.push_back(tmp);
        }
    }
    cout << "size = " << ivec.size() << endl;
    for (auto &item : ivec)
    {
        //cout << item.word << ":" << item.cnt << endl;
        ofs << item.word << " " << item.cnt << "\n";
    }
    ifs.close();
    ofs.close();
}

int main(int argc, char *argv[])
{
    func();
    return 0;
}