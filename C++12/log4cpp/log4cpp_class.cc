#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using namespace std;
using namespace log4cpp;

class Mylogger
{
public:
    static Mylogger* getinstance()
    {
        if(nullptr == pinstance)
            pinstance = new Mylogger();
        return pinstance;
    }
    static Mylogger* destroy()
    {
        if(pinstance)
            delete pinstance;
    }
    void write_log(int, const char *msg);
    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);
private:
    Mylogger(){};
    ~Mylogger(){cout << "hh" << endl;};
private:
    static Mylogger* pinstance;

};

Mylogger *Mylogger::pinstance = new Mylogger;

void Mylogger::write_log(int flag, const char *msg)//将日志信息同时输入到终端和文件
{
    PatternLayout *p1 = new PatternLayout();
    p1->setConversionPattern("%d %c [%p] %m%n");
    OstreamAppender *ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
    ostreamAppender->setLayout(p1);

    PatternLayout *p2 = new PatternLayout();
    p2->setConversionPattern("%d %c [%p] %m%n");
    FileAppender *fileAppender = new FileAppender("fileAppender", "tmp_log.txt");
    fileAppender->setLayout(p2);

    Category &root = Category::getRoot();
    root.setPriority(Priority::DEBUG);
    root.addAppender(ostreamAppender);
    root.addAppender(fileAppender);

    
    if(flag == 1)
    {
        root.warn(msg);
    }
    else if(flag == 2)
    {
        root.error(msg);
    }
    else if(flag == 3)
    {
        root.debug(msg);
    }
    else if(flag == 4)
    {
        root.info(msg);
    }
    Category::shutdown();
}

void Mylogger::warn(const char *msg)
{
    write_log(1,msg);
}

void Mylogger::error(const char *msg)
{
    write_log(2,msg);
}
void Mylogger::debug(const char *msg)
{
    write_log(3,msg);
}
void Mylogger::info(const char *msg)
{
    write_log(4,msg);
}


int main(int argc, char *argv[])
{
    /*• __LINE__：在源代码中插入当前源代码行号
    • __FILE__：在源文件中插入当前源文件名
    • __FUNCTION__：函数名
    • __DATE__：在源文件中插入当前的编译日期
    • __TIME__：在源文件中插入当前编译时间*/
    string str_filename = __FILE__;
    string str_function = __FUNCTION__;
    string str = str_filename + " " + str_function + ": ";
    
    Mylogger *log = Mylogger::getinstance();
    log->error("this is a error");
    log->error((((str += to_string(__LINE__) + " ")+= "this is a error") + " ").c_str());
    str = str_filename + " " + str_function + ": ";
    log->warn((((str += to_string(__LINE__) + " ")+= "this is a warn") + " ").c_str());
    str = str_filename + " " + str_function + ": ";
    log->debug((((str += to_string(__LINE__) + " ")+= "this is a debug") + " ").c_str());
    str = str_filename + " " + str_function + ": ";
    log->info((((str += to_string(__LINE__) + " ")+= "this is a info") + " ").c_str());
    log->destroy();
    return 0;
}