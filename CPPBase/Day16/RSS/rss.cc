#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::string;

using namespace tinyxml2;

void test()
{
    XMLDocument doc;
    doc.LoadFile("coolshell.xml");
    if(doc.ErrorID())
    {
        std::cerr << "loadFile fail" << endl;
        return;
    }

    XMLElement *itemNode = 
        doc.FirstChildElement("rss")->FirstChildElement("channel")
        ->FirstChildElement("item");
    /* if(itemNode) */
    while(itemNode)
    {
        //还可以在此处判断指针是不是空指针，然后在赋值给string字符串
        string title = itemNode->FirstChildElement("title")->GetText();
        string link=  itemNode->FirstChildElement("link")->GetText();
        string description = itemNode->FirstChildElement("description")->GetText();
        string content = itemNode->FirstChildElement("content:encoded")->GetText();

#if 1
        //html的标签
        std::regex reg("<[^>]+>");//通用正则表达式(主要研究一下正则表达式的规则)
        description = regex_replace(description, reg, "");//regex_replace函数的使用
        content = regex_replace(content, reg, "");
#endif
    
        cout << "title = " << title << endl;
        cout << "link = " << link << endl;
        cout << "description = " << description << endl;
        cout << "content = " << content << endl;

        itemNode = itemNode->NextSiblingElement("item");//找到下一篇item
    }
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

