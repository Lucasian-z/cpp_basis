#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Appender.hh>

#include <iostream>
#include <string>
using namespace std;
using namespace log4cpp;

/*  • __LINE__：在源代码中插入当前源代码行号
    • __FILE__：在源文件中插入当前源文件名
    • __FUNCTION__：函数名
    • __DATE__：在源文件中插入当前的编译日期
    • __TIME__：在源文件中插入当前编译时间    */

//定义一个宏，以输出日志信息所在的文件名，函数名和所在行
#define getinfo(msg) (string(msg).append(" [").append(__FILE__).append(" ").\
        append(__FUNCTION__).append(":").append(to_string(__LINE__)).append("]")).c_str()

class Mylogger
{
public:
    static Mylogger *getstance()
    {
        if (_pinstance == nullptr)
            _pinstance = new Mylogger();
        return _pinstance;
    }
    void destory()
    {
        if (_pinstance)
            delete _pinstance;
        _pinstance = nullptr;
    }
    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);

private:
    Mylogger();
    ~Mylogger();
    PatternLayout *_p1;
    PatternLayout *_p2;
    OstreamAppender *_ostreamAppender;
    FileAppender *_fileAppender;
    Category &_root;
    static Mylogger *_pinstance;
};

Mylogger* Mylogger::_pinstance = nullptr;

Mylogger::Mylogger()
    : _p1(new PatternLayout())
    , _p2(new PatternLayout())
    , _ostreamAppender(new OstreamAppender("ostreamAppender", &cout))
    , _fileAppender(new FileAppender("fileAppender", "log.txt"))
    , _root(Category::getRoot())
{
    _p1->setConversionPattern("%d %c [%p] %m%n");
    _p2->setConversionPattern("%d %c [%p] %m%n");
    _ostreamAppender->setLayout(_p1);
    _fileAppender->setLayout(_p2);
    cout << "nihao" << endl;
    _root.setPriority(Priority::DEBUG);
    _root.addAppender(_ostreamAppender);
    _root.addAppender(_fileAppender);
    //Category::shutdown();
}

Mylogger::~Mylogger()
{
    Category::shutdown();
    cout << "析构函数" << endl;
}

void Mylogger::warn(const char *msg)
{
    _root.warn(msg);
}

void Mylogger::error(const char *msg)
{
    _root.error(msg);
}

void Mylogger::debug(const char *msg)
{
    _root.debug(msg);
}

void Mylogger::info(const char *msg)
{
    _root.info(msg);
}

int main(int argc, char *argv[])
{
    Mylogger *p = Mylogger::getstance();
    p->warn(getinfo("warn"));
    p->error(getinfo("error"));
    p->debug(getinfo("debug"));
    p->info(getinfo("info"));
    p->destory();
    return 0;
}
