#pragma once
#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<memory>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include"QueryResult.h"

//前向申明
class QueryResult;

//TextQuery类用于文本查询，查询结果交给QueryResult处理
class TextQuery
{
public:
    //使用别名定义行号类型
    using line_no=std::vector<std::string>::size_type;

    //构造函数，接收一个文件输入流，并读取文件内容
    TextQuery(std::ifstream &);

    //查询给定单词，返回查询结果
    QueryResult query(const std::string&)const;

    //调试辅助函数，打印词典内容
    void dispaly_map();

private:
    //智能指针，指向文件内容的向量
    std::shared_ptr<std::vector<std::string>>file;

    //映射每个单词到其出现的行号集合
    std::map<std::string,std::shared_ptr<std::set<line_no>>>wm;

    //规范文本：移除标点符号并将所有字符小写
    static std::string cleanup_str(const std::string&);
};


#endif
