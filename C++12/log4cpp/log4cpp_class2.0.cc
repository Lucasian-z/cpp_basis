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

#define logwarn(args...) logwarnfunc(__FILE__, __FUNCTION__, __LINE__, args);
#define logerror(args...) logerrorfunc(__FILE__, __FUNCTION__, __LINE__, args);
#define logdebug(args...) logdebugfunc(__FILE__, __FUNCTION__, __LINE__, args);
#define loginfo(args...) loginfofunc(__FILE__, __FUNCTION__, __LINE__, args);
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
    template<class...Args>
    void warn(Args...args);
    template<class...Args>
    void error(Args...args);
    template<class...Args>
    void debug(Args...args);
    template<class...Args>
    void info(Args...args);

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
template<class...Args>
void Mylogger::warn(Args...args)
{
    _root.warn(args...);
}
template<class...Args>
void Mylogger::error(Args...args)
{
    _root.error(args...);
}
template<class...Args>
void Mylogger::debug(Args...args)
{
    _root.debug(args...);
}
template<class...Args>
void Mylogger::info(Args...args)
{
    _root.info(args...);
}

template<class...Args>
void logwarnfunc(const char* file, const char* func, int line, const char *msg, Args...args)
{
    string str = string(msg).append(" [").append(file).append(" ").\
        append(func).append(":").append(to_string(line)).append("]");
        Mylogger::getstance()->warn(str.c_str(), args...);
}
template<class...Args>
void logerrorfunc(const char* file, const char* func, int line, const char *msg, Args...args)
{
    string str = string(msg).append(" [").append(file).append(" ").\
        append(func).append(":").append(to_string(line)).append("]");
        Mylogger::getstance()->error(str.c_str(), args...);
}
template<class...Args>
void logdebugfunc(const char* file, const char* func, int line, const char *msg, Args...args)
{
    string str = string(msg).append(" [").append(file).append(" ").\
        append(func).append(":").append(to_string(line)).append("]");
        Mylogger::getstance()->debug(str.c_str(), args...);
}
template<class...Args>
void loginfofunc(const char* file, const char* func, int line, const char *msg, Args...args)
{
    string str = string(msg).append(" [").append(file).append(" ").\
        append(func).append(":").append(to_string(line)).append("]");
        Mylogger::getstance()->info(str.c_str(), args...);
}

void test()
{
    int number = 22;
    logwarn("this is a warn %d,%s", number,"hhh");
    logerror("this is a error %d", number);
}
int main(int argc, char *argv[])
{
    test();
    return 0;
}