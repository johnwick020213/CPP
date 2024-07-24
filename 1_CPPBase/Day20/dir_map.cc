#include <iostream>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::map;
using std::string;
using std::cerr;

class Dictionary
{
public:
    void readFile(const string & filename);
    void storeFile(const string & filename);
private:
    map<string,int> _dir;
};

void clearWord(string &word)
{
    auto it=word.begin();
    while(it!=word.end())
    {
        if(!isalpha(*it))
        {
            it=word.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Dictionary::readFile(const string & filename)
{
    ifstream ifs(filename);

    if(!ifs)
    {
        cerr<<"文件打开失败"<<endl;
        return;
    }

    string line;
    while(getline(ifs,line))
    {
        istringstream iss(line);
        string word;
        while(iss>>word)
        {
            clearWord(word);

            if(word!=string())
            {
                ++_dir[word];
            }
        }
    }
    ifs.close();
}


void Dictionary::storeFile(const string &filename)
{
    ofstream oss(filename);

    if(!oss)
    {
        cerr<<"存储文件打开失败"<<endl;
        return;
    }

    map<string,int>::iterator it=_dir.begin();
    for(;it!=_dir.end();++it)
    {
        oss<<it->first<<" "<<it->second<<endl;
    }

    oss.close();
}


void test0()
{
    Dictionary dir;
    dir.readFile("The_Holy_Bible.txt");
    dir.storeFile("dirmap.txt");
}

int main()
{
   test0();
    return 0;
}

