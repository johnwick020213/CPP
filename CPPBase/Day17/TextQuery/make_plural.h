#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include <cstddef>
using std::size_t;  // 使用标准库中的 size_t 类型

#include <string>
using std::string;  // 使用标准库中的 string 类型

#include <iostream>
using std::cout; using std::endl;  // 使用标准库中的 cout 和 endl

// 返回单词的复数形式，如果计数器大于1
inline
string make_plural(size_t ctr, const string &word, const string &ending)
{
    // 如果 ctr 大于 1，返回单词加上结尾，否则返回原单词
    return (ctr > 1) ? word + ending : word;
}

#endif

