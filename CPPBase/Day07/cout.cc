#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>


using namespace std;

struct Record
{
    string _word;
    int _frequency;
};

class Dictionary
{
public:
    void read(const string &filename);
    void store(const string&filename);
private:
    vector<Record>_dict;
};

void Dictionary::read(const string &filename)
{
    //打开输入文件
    ifstream infile(filename);
    if(!infile.is_open()){
        cerr<<"打开失败："<<filename<<endl;
        return;
    }

    //使用unordered_map统计单词
    unordered_map<string,int> wordCount;
    string line;
    //逐行读取文件
    while(getline(infile,line)){
        stringstream ss(line);
        string word;
        //提取每一个单词
        while(ss>>word){
            //移除单词非字母字符
            word.erase(remove_if(word.begin(),word.end(),[](char c){return !isalpha(c);}),word.end());
            //单转换小写
            transform(word.begin(),word.end(),word.begin(),::towlower);

            //统计频率
            if(!word.empty()){
                wordCount[word]++;
            }
        }
    }

    //将unordered_map中数据复制到vector
    for(const auto &entry:wordCount){
        _dict.push_back({entry.first,entry.second});
    }

    //按字母顺序排序vector
    sort(_dict.begin(),_dict.end(),[](const Record &a,const Record &b){
         return a._word<b._word;
         });
}

void Dictionary::store(const string &filename){
    //打开输出文件
    ofstream outfile(filename);
    if(!outfile.is_open()){
        cerr<<"文件打开失败:"<<filename<<endl;
        return;
    }

    //遍历容器
    for(const auto &record:_dict){
        outfile<<record._word<<" "<<record._frequency<<endl;
    }
}

int main()
{
    // 创建Dictionary对象
    Dictionary dict;
    // 调用read方法读取并统计单词频率
    dict.read("The_Holy_Bible.txt");
    // 调用store方法将统计结果存储到文件
    dict.store("dict.txt");
    return 0;
}

