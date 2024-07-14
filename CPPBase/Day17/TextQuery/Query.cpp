#include "Query.h"
#include "TextQuery.h"

#include <memory>
using std::shared_ptr;  // 使用标准库中的 shared_ptr 智能指针

#include <set>
using std::set;  // 使用标准库中的 set 集合

#include <algorithm>
using std::set_intersection;  // 使用标准库中的 set_intersection 算法

#include <iostream>
using std::ostream;  // 使用标准库中的 ostream

#include <cstddef>
using std::size_t;  // 使用标准库中的 size_t 类型

#include <iterator>
using std::inserter;  // 使用标准库中的 inserter 迭代器

#include <vector>
using std::vector;  // 使用标准库中的 vector 容器

#include <string>
using std::string;  // 使用标准库中的 string 类型

// NotQuery::eval 函数实现：返回其操作数结果集中没有的行
QueryResult NotQuery::eval(const TextQuery& text) const
{
    // 通过 Query 操作数进行虚函数调用
    QueryResult result = query.eval(text);

    // 初始化一个空的结果集合
    shared_ptr<set<line_no>> ret_lines(new set<line_no>);

    // 遍历操作数结果集中的行
    QueryResult::line_it beg = result.begin(), end = result.end();

    // 对输入文件的每一行进行检查，如果该行不在操作数结果集中，则将其行号添加到 ret_lines
    vector<string>::size_type sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        // 如果还没有处理完操作数结果集中的所有行，检查此行是否存在
        if (beg == end || *beg != n) 
            ret_lines->insert(n);  // 如果不在结果集中，添加此行
        else if (beg != end) 
            ++beg; // 否则获取结果集中下一行的行号（如果有）
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

// AndQuery::eval 函数实现：返回其操作数结果集的交集
QueryResult AndQuery::eval(const TextQuery& text) const
{
    // 通过 Query 操作数进行虚函数调用，获取操作数的结果集
    QueryResult left = lhs.eval(text), right = rhs.eval(text);

    // 用于存储 left 和 right 的交集的集合
    shared_ptr<set<line_no>> ret_lines(new set<line_no>);

    // 将两个范围的交集写入目标迭代器，目标迭代器在此调用中将元素添加到 ret_lines
    set_intersection(left.begin(), left.end(), 
                     right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

// OrQuery::eval 函数实现：返回其操作数结果集的并集
QueryResult OrQuery::eval(const TextQuery& text) const
{
    // 通过 Query 成员 lhs 和 rhs 进行虚函数调用
    // eval 调用返回每个操作数的 QueryResult
    QueryResult right = rhs.eval(text), left = lhs.eval(text);

    // 将左操作数的行号复制到结果集中
    shared_ptr<set<line_no>> 
        ret_lines(new set<line_no>(left.begin(), left.end()));

    // 插入右操作数的行号
    ret_lines->insert(right.begin(), right.end());
    // 返回表示 lhs 和 rhs 并集的新 QueryResult
    return QueryResult(rep(), ret_lines, left.get_file());
}

