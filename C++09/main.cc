#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>//正则匹配
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

struct RssItem
{
    string title;
    string link;
    string description;
    string content;
};
    
class RssReader
{
public:
    RssReader();
        
    void parseRss();//解析
    void dump(const string & filename);//输出
private:
    vector<RssItem> _rss;
    XMLDocument _doc;
    void format(string &instr)//正则匹配并替换
    {
        regex str1("nbsp");
        regex str2("-&gt");
        regex str3("<.*?>");
        instr = regex_replace(instr, str1, "");
        instr = regex_replace(instr, str2, "");
        instr = regex_replace(instr, str3, "");
    }
};

RssReader::RssReader()
{
    _doc.LoadFile("coolshell.xml");//打开xml
    cout << "RssReader()" << endl;
}

void RssReader::parseRss()
{
    XMLElement *root = _doc.RootElement();
    XMLElement *channel = root->FirstChildElement("channel");
    XMLElement *item = channel->FirstChildElement("item");

    while (item)
    {
        XMLElement *itemnode = item->FirstChildElement();
        RssItem tmp;
        while(itemnode)
        {
            if(!strcmp(itemnode->Name(), "title"))
                tmp.title = itemnode->GetText();
            else if(!strcmp(itemnode->Name(), "link"))
                tmp.link = itemnode->GetText();
            else if(!strcmp(itemnode->Name(), "description"))
                tmp.description = itemnode->GetText();
            else if(!strcmp(itemnode->Name(), "content:encoded"))
                tmp.content = itemnode->GetText();
            itemnode = itemnode->NextSiblingElement();
        }
        format(tmp.content);
        format(tmp.description);
        _rss.push_back(tmp);
        item = item->NextSiblingElement("item");
    }
}

void RssReader::dump(const string & filename)
{
    ofstream fos("res.txt", std::ios::app);
    for(const auto &i : _rss)
    {
        fos << "<title>" << i.title << "</title>" << endl
            << "<link>" << i.link << "</link>" << endl
            << "<description>" << i.description << "</description" << endl
            << "<content>" << i.content << "</content>" << endl;
    }
}

int main(int argc, char *argv[])
{
    RssReader reader;
    reader.parseRss();
    reader.dump("f");
    return 0;
}