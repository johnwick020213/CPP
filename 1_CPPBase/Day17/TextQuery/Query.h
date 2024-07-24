#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

// 抽象基类，作为具体查询类型的基类；所有成员都是私有的
class Query_base 
{
    friend class Query;  // 允许 Query 类访问 Query_base 的私有成员
protected:
    typedef TextQuery::line_no line_no; // 在 eval 函数中使用
    virtual ~Query_base() { }
private:
    // eval 返回与此查询匹配的 QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0; 
    // rep 返回查询的字符串表示
	virtual std::string rep() const = 0;
};

// 管理 Query_base 继承层次结构的接口类
class Query
{
    // 这些运算符需要访问 shared_ptr 构造函数
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    // 构造一个新的 WordQuery
    Query(const std::string&);

    // 接口函数：调用对应的 Query_base 操作
    QueryResult eval(const TextQuery &t) const 
	{
		return q->eval(t); 
	}

	std::string rep() const 
	{ 
		return q->rep(); 
	}
private:
    // 使用 shared_ptr 构造函数
    Query(std::shared_ptr<Query_base> query)
	: q(query)
	{ 

	}
    std::shared_ptr<Query_base> q;
};

// 重载输出运算符，输出 Query 的字符串表示
inline std::ostream &operator<<(std::ostream &os, const Query &query) 
{
    // Query::rep 通过 Query_base 指针调用虚函数 rep() 
	return os << query.rep(); 
}

// 具体类：WordQuery 定义了所有继承的纯虚函数
class WordQuery : public Query_base 
{
    friend class Query; // Query 使用 WordQuery 构造函数
    WordQuery(const std::string &s)
	: query_word(s)
	{ 

	}

    // 具体类：WordQuery 定义了所有继承的纯虚函数
    QueryResult eval(const TextQuery &t) const
    { 
		return t.query(query_word); 
	}

	std::string rep() const 
	{ 
		return query_word; 
	}
    std::string query_word;   // 要搜索的单词 
};

// 构造函数，初始化 WordQuery
inline Query::Query(const std::string &s)
: q(new WordQuery(s)) 
{ 

}

// 具体类：NotQuery 定义了所有继承的纯虚函数
class NotQuery : public Query_base 
{
    friend Query operator~(const Query &);

    NotQuery(const Query &q)
	: query(q) 
	{

	}

    // 具体类：NotQuery 定义了所有继承的纯虚函数
	std::string rep() const 
	{
		return "~(" + query.rep() + ")";
	}

    QueryResult eval(const TextQuery&) const;
    Query query;
};

// 抽象类：BinaryQuery 不定义 eval 
class BinaryQuery : public Query_base 
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s)
	: lhs(l), rhs(r), opSym(s) 
	{ 

	}

    // 抽象类：BinaryQuery 不定义 eval 
	std::string rep() const 
	{ 
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; 
	}

    Query lhs, rhs;    // 左、右操作数
    std::string opSym; // 运算符的名称
};
    
// 具体类：AndQuery 继承 rep 并定义剩余的纯虚函数
class AndQuery : public BinaryQuery 
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right)
    : BinaryQuery(left, right, "&") 
	{ 

	}

    // 具体类：AndQuery 继承 rep 并定义剩余的纯虚函数
    QueryResult eval(const TextQuery&) const;
};

// 具体类：OrQuery 继承 rep 并定义剩余的纯虚函数
class OrQuery : public BinaryQuery 
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right)
	: BinaryQuery(left, right, "|") 
	{

	}

    QueryResult eval(const TextQuery&) const;
};

// 重载 & 运算符，返回 AndQuery
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

// 重载 | 运算符，返回 OrQuery
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

// 重载 ~ 运算符，返回 NotQuery
inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

std::ifstream& open_file(std::ifstream&, const std::string&);
TextQuery get_file(int, char**);
bool get_word(std::string &);
bool get_words(std::string &, std::string &);
std::ostream &print(std::ostream&, const QueryResult&);

#endif

