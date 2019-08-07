#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>

#include <iostream>
using namespace std;
using namespace log4cpp;

int main(int argc, char *argv[])
{
    PatternLayout *p1 = new PatternLayout();
    p1->setConversionPattern("%d %c [%p] %m%n");
    PatternLayout *p2 = new PatternLayout();
    p2->setConversionPattern("%d %c [%p] %m%n");
    PatternLayout *p3 = new PatternLayout();
    p3->setConversionPattern("%d %c [%p] %m%n");

    OstreamAppender *ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
    ostreamAppender->setLayout(p1);
    
    FileAppender *filestreamAppender = new FileAppender("filestreamAppender", "hu.log");
    filestreamAppender->setLayout(p2);

    RollingFileAppender *rollingFileAppender = new RollingFileAppender("rollingFileAppender", "li.log",128,3);
    rollingFileAppender->setLayout(p3);

    Category &root = Category::getRoot();
    root.setPriority(Priority::NOTICE);
    root.addAppender(ostreamAppender);
    root.addAppender(filestreamAppender);
    root.addAppender(rollingFileAppender);

    for(int i = 0; i < 2; ++i)
    {
        root.alert("this is a alert");
        root.fatal("致命故障");
        root.warn("this is a warn");
        root.notice("%d this is a notice", i);
    }
    Category::shutdown();
    return 0;
}