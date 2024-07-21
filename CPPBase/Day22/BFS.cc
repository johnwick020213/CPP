#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

class Wordmap;

class WordList
{
public:
    WordList(size_t length)
    : word_length(length)
    {
    }

    void addWord(const string& word)
    {
        if (word.size() != word_length)
        {
            cout << "单词长度不统一,请输入长度为" << word_length << "的单词" << endl;
            return;
        }
        
        wordlist.insert(word);
    }
    
    friend class Wordmap;

private:
    size_t word_length;
    unordered_set<string> wordlist;
};

static vector<string> back_way;  // 存储当前路径
static multiset<int> waylength;  // 存储所有路径的长度
static int i = 0;                // 路径长度计数器

class Wordmap
{
public:
    Wordmap(WordList& wd)
    {
        for (auto it1 : wd.wordlist)
        {
            for (auto it2 : wd.wordlist)
            {
                if (wordlike(it1, it2))
                {
                    _wordhash.insert({it1, it2});
                }
            }
        }
    }

    bool wordlike(const string& str1, const string& str2)
    {
        int diffCount = 0; // 记录不同字母的数量

        // 遍历字符串，比较每个字符
        for (size_t i = 0; i < str1.length(); ++i)
        {
            if (str1[i] != str2[i])
            {
                ++diffCount;
                // 如果不同字母的数量超过1，直接返回false
                if (diffCount > 1)
                {
                    return false;
                }
            }
        }

        // 如果不同字母的数量正好是1，则返回true
        return diffCount == 1;
    }

    int wordPath(const string& begin, const string& end)  // 修改为const引用
    {
        if (begin == end)
        {
            cout << "起始和结束单词相同" << endl;
            return 0;
        }

        if (_wordhash.find(end) == _wordhash.end())
        {
            cout << "终点单词不存在" << endl;
            return 0;
        }

        if (_wordhash.find(begin) == _wordhash.end())
        {
            cout << "起始单词不存在" << endl;
            return 0;
        }

        // 清空之前的路径信息
        back_way.clear();
        waylength.clear();
        i = 0;

        // 开始寻找路径
        findWay(begin, end);

        if (waylength.empty())
        {
            cout << "没有找到路径" << endl;
            return 0;
        }
        else
        {
            cout << "最短次数: " << *(waylength.begin()) << endl;
            return *(waylength.begin());
        }
    }

private:
    vector<string> findValue(const string& begin)  // 修改为const引用
    {
        vector<string> temp;
        auto range = _wordhash.equal_range(begin);
        for (auto it = range.first; it != range.second; ++it)
        {
            auto it2 = find(back_way.begin(), back_way.end(), it->second);
            if (it2 == back_way.end()) // 只推入还未经过的单词
            {
                temp.push_back(it->second);
            }
        }
        return temp;
    }

    void findWay(const string& begin, const string& end)  // 修改为const引用
    {
        back_way.push_back(begin);  // 增加当前路径的开始节点
        vector<string> way = findValue(begin);

        for (auto& it : way)
        {
            if (it == end)
            {
                waylength.insert(i);
            }
            else
            {
                ++i;  // 递归之前先增加计数
                findWay(it, end);
                --i;  // 回溯时减少计数
            }
        }

        back_way.pop_back();  // 回溯时移除当前路径的开始节点
    }

    unordered_multimap<string, string> _wordhash;  
};

int main()
{
    WordList wd(3);
    wd.addWord("dog");
    wd.addWord("hot");
    wd.addWord("dot");
    wd.addWord("cog");
    wd.addWord("log");
    wd.addWord("lot");
    wd.addWord("hit");

    Wordmap mmap(wd);
    mmap.wordPath("hit", "cog");  // 修改调用为wordPath

    return 0;
}

