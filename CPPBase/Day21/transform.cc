#include <iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace::std;

class TF_word
{
    public:
        void read_order(const string &filename);
        void transform_origin(const string &filename);
    private:
        unordered_map<string,string> _order;
        vector<string> _origin;
};

void TF_word::read_order(const string &filename)
{
    ifstream ifs(filename);

    if(!ifs)
    {
        cerr<<"规则文件不存在"<<endl;
        return;
    }

    string line;
    while(getline(ifs,line))
    {
        istringstream iss(line);
        string key,value;
        iss>>key>>value;
        _order.insert(make_pair(key,value));
    }

    ifs.close();
}

void TF_word::transform_origin(const string &filename)
{
    ifstream ifs(filename);

    if(!ifs)
    {
        cerr<<"目标文件不存在"<<endl;
        return;
    }

    string line;
    while(getline(ifs,line))
    {
        istringstream iss(line);
        string word;
        while(iss>>word)
        {
            _origin.push_back(word);
          
        }
        _origin.push_back("\n");
    }
    
   ofstream ofs("order_file.txt");
   
   for(vector<string>::iterator word=_origin.begin();word!=_origin.end();++word)
   {
        auto it=_order.find(*word);
        if(it!=_order.end())
        {
            *word=it->second;
        }
        
        if(*word!="\n")
            ofs<<*word<<" ";
        else
            ofs<<*word;
   }
   ofs<<endl;

   ifs.close();
   ofs.close();
}


int main()
{
    TF_word tf;
    tf.read_order("map.txt");
    tf.transform_origin("file.txt");
    return 0;
}

