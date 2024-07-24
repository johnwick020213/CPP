#include<iostream>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/Category.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

void test0(){
    //1.设置布局
    PatternLayout *ptn1=new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    //2.设置目的地
    OstreamAppender *pos =new OstreamAppender("console",&cout);
    //目的地绑定布局
    pos->setLayout(ptn1);

    //3.创建记录器
    Category & cat =Category::getInstance("cate");
    //记录器设置优先级
    cat.setPriority(Priority::WARN);
    //记录器设置目的地
    cat.addAppender(pos);

    cat.error("this is an error msg");

    Category::shutdown();
}

int main(){
    test0();
    return 0;
}
