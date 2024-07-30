/**
 * @file InetAddress.cpp
 * @author johnwick
 * @brief InetAddress类的实现文件，提供InetAddress类的成员函数定义。
 */

#include "InetAddress.h"
#include <strings.h>
#include <arpa/inet.h>

/**
 * @brief 构造函数，使用IP地址和端口初始化InetAddress对象。
 * @param ip IP地址。
 * @param port 端口号。
 * 
 * 该构造函数初始化一个`sockaddr_in`结构体，用于表示网络地址。
 */
InetAddress::InetAddress(const string &ip, unsigned short port)
{
    ::bzero(&_addr, sizeof(struct sockaddr_in));
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(port); // 将主机字节序转换为网络字节序
    _addr.sin_addr.s_addr = inet_addr(ip.c_str()); // 将IP地址从字符串转换为网络字节序
}

/**
 * @brief 构造函数，使用现有的`sockaddr_in`结构体初始化InetAddress对象。
 * @param addr `sockaddr_in`结构体。
 */
InetAddress::InetAddress(const struct sockaddr_in &addr)
: _addr(addr)
{

}

/**
 * @brief 析构函数，销毁InetAddress对象。
 */
InetAddress::~InetAddress()
{

}

/**
 * @brief 获取IP地址。
 * @return IP地址的字符串表示。
 * 
 * 该函数将网络字节序的IP地址转换为本机字节序，并返回字符串形式的IP地址。
 */
string InetAddress::ip() const
{
    return string(inet_ntoa(_addr.sin_addr)); // 将网络字节序的IP地址转换为字符串
}

/**
 * @brief 获取端口号。
 * @return 端口号。
 * 
 * 该函数将网络字节序的端口号转换为本机字节序，并返回端口号。
 */
unsigned short InetAddress::port() const
{
    return ntohs(_addr.sin_port); // 将网络字节序的端口号转换为主机字节序
}

/**
 * @brief 获取`sockaddr_in`结构体的指针。
 * @return 指向`sockaddr_in`结构体的指针。
 */
const struct sockaddr_in *InetAddress::getInetAddrPtr() const
{
    return &_addr;
}

