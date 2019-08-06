#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/SimpleLayout.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using namespace std;
using namespace log4cpp;

int main(int argc, char *argv[])
{
    OstreamAppender *ostreamAppender = new OstreamAppender("ostreamAppender",&cout);
    ostreamAppender->setLayout(new BasicLayout);

    Category &root = Category::getRoot();
    root.setPriority(Priority::INFO);
    root.addAppender(ostreamAppender);

    root.notice("this is a notice");

    root.shutdown();
    return 0;
}