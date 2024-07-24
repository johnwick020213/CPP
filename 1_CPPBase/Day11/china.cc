#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include<algorithm>

using namespace std;

class TextQuery
{
public:
    void readFile(const string &filename);
    void query(const string &word) const;

private:
    vector<string> _lines;
    map<string,set<int>> _wordNumbers;
    map<string,int>_dict;

    static string cleanWord(const string &word); 
    static string toLower(const string &str);
};

void TextQuery::readFile(const string &filename)
{
    ifstream file(filename);
    if(!file)
    {
        cerr<<"文件打开失败"<<filename<<endl;
        return;
    }

    string line;
    int lineNumber=1;
    while(getline(file,line))
    {
        _lines.push_back(line);

        istringstream stream(line);
        string word;
        while(stream>>word)
        {
            word=cleanWord(word);
            if(!word.empty())
            {
                word=toLower(word);
                _wordNumbers[word].insert(lineNumber);
                _dict[word]++;

            }
           
        }

        lineNumber++;
    }
    file.close();
}

void TextQuery::query(const string &word)const
{
    string cleanQueryWord = toLower(cleanWord(word));
    auto it =_wordNumbers.find(cleanQueryWord);
    if(it!=_wordNumbers.end())
    {
        const set<int>&lineNumber=it->second;
        cout<<word<<" occurs "<<_dict.at(cleanQueryWord)<<"times."<<endl;
        for(int lineNumber:lineNumber)
        {
            cout<<"(line "<<lineNumber<<")"<<_lines[lineNumber-1]<<endl;

        }
    }
    else
    {
        cout<<word<<" 在文章中没出现过"<<endl;
    }
    
}

string TextQuery::cleanWord(const string &word)
{
    string cleaned;
    for(char ch:word)
    {
        if(isalnum(ch))
        {
            cleaned+=ch;
        }
    }
    return cleaned;
}

string TextQuery::toLower(const string &str)
{
    string lowerStr=str;
    transform(lowerStr.begin(),lowerStr.end(),lowerStr.begin(),::towlower);
    return lowerStr;
}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        cerr<<"Usage:"<<argv[0]<<" <filename><queryWord>"<<endl;
        return 1;
    }

    string filename =argv[1];
    string queryWord =(argc>2)?argv[2]:"element";

    TextQuery tq;
    tq.readFile(filename);
    tq.query(queryWord);

    return 0;
}
