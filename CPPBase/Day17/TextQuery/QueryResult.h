#pragma once
#ifdef QUERYRESULT_H
#define QUERYRESULT_H

#include<memory>
#include<string>
#include<vector>
#include<set>
#include<iostream>

class QueryResult
{
    //友元声明，允许print函数访问QueryResult的私有成员
    friend std::ostream &print(std::ostream&,const QueryResult&);
public:
    //定义类型别名称，方便代码书写和维护
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;

    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>>p.
                std::shared_ptr<std::vector<std::string>>f)
    :sought(s)//查询的单词
     ,lines(p)//单词出现的行号集合
     ,file(f)//输入文件内容
    {}

    //返回查询结果中的行号的数量
    std::set<line_no>::size_type size() const
    {
        return lines->size();
    }

    //返回行号集合的开始迭代器
    line_it begin()const
    {
        return lines->begin();
    }

    //返回行号集合的结束迭代器
    line_it end()const
    {
        return lines->end();
    }

    //返回输入文件内容的智能指针
    std::shared_ptr<std::vector<std::string>>get_file()
    {
        return file;
    }

private:
    std::string sought;//查询的单词
    std::shared_ptr<std::set<line_no>>lines;//单词出现的行号集合、
    std::shared_ptr<std::vector<std::string>>file;//输入文件内容
};

//打印查询结果
std::ostream &print(std::ostream&,const QueryResult&);

#endif

