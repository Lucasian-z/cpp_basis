#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
using namespace std;
using namespace log4cpp;

int main(int argc, char *argv[])
{
    PatternLayout* playout1 = new PatternLayout();
    playout1->setConversionPattern("[%d] %c [%p] %m%n");
    OstreamAppender *ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
    ostreamAppender->setLayout(playout1);

    PatternLayout* playout2 = new PatternLayout();
    playout2->setConversionPattern("[%d] %c [%p] %m%n");
    FileAppender *fileAppender = new FileAppender("fileAppender", "huai.log");
    fileAppender->setLayout(playout2);
    Category &root = Category::getRoot();
    root.setPriority(Priority::NOTICE);
    root.addAppender(ostreamAppender);
    root.addAppender(fileAppender);

    root.fatal("this is a fatal mistake");
    root.warn("this is a warn");

    Category::shutdown();
    return 0;
}