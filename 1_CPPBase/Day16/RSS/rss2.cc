#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

using namespace tinyxml2;

struct RSSIteam
{
    string _title;
    string _link;
    string _description;
    string _content;
};

class RSS
{
public:
    RSS(size_t capa)
    {
        _rss.reserve(capa);
    }

    //读文件
    void read(const string &filename)
    {
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        if(doc.ErrorID())
        {
            std::cerr << "loadFile fail" << endl;
            return;
        }

        size_t idx = 0;

        XMLElement *itemNode = 
            doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
        while(itemNode)
        {
            string title = itemNode->FirstChildElement("title")->GetText();
            string link=  itemNode->FirstChildElement("link")->GetText();
            string description = itemNode->FirstChildElement("description")->GetText();
            string content = itemNode->FirstChildElement("content:encoded")->GetText();

            std::regex reg("<[^>]+>");//通用正则表达式
            description = regex_replace(description, reg, "");
            content = regex_replace(content, reg, "");
        
            RSSIteam rssItem;

            rssItem._title = title;
            rssItem._link = link;
            rssItem._description = description;
            rssItem._content = content;

            _rss.push_back(rssItem);
            ++idx;

            itemNode = itemNode->NextSiblingElement("item");
        }
    }

    //写文件
    void store(const string &filename)
    {
        ofstream ofs(filename);
        if(!ofs)
        {
            std::cerr << "open " << filename << " fail!" << endl;
            return;
        }

        for(size_t idx = 0; idx != _rss.size(); ++idx)
        {
            ofs << "<doc><docid>" << idx + 1
                << "</docid><title>" << _rss[idx]._title 
                << "</title><link>" << _rss[idx]._link 
                << "</link><description>" << _rss[idx]._description
                << "</description><content>" << _rss[idx]._content << "</content></doc>";
            ofs << '\n';
        }

        ofs.close();
    }
private:
    vector<RSSIteam> _rss;
};

int main(int argc, char **argv)
{
    RSS rss(4000);
    rss.read("coolshell.xml");
    rss.store("pagelib.dat");
    return 0;
}
