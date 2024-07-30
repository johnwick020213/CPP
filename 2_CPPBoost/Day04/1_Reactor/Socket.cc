/**
 * @file Socket.cpp
 * @author johnwick
 * @brief Socket类的实现文件，提供Socket类的成员函数定义。
 */

#include "Socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief 构造函数，创建一个新的套接字。
 * 
 * 使用IPv4地址族和流式套接字类型创建一个新的套接字。
 * 如果创建失败，会打印错误信息。
 */
Socket::Socket()
{
    _fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if(_fd < 0)
    {
        perror("socket");
        return;
    }
}

/**
 * @brief 构造函数，使用现有的文件描述符初始化Socket对象。
 * @param fd 文件描述符。
 */
Socket::Socket(int fd)
: _fd(fd)
{

}

/**
 * @brief 析构函数，关闭套接字。
 */
Socket::~Socket()
{
    close(_fd);
}

/**
 * @brief 获取套接字的文件描述符。
 * @return 套接字的文件描述符。
 */
int Socket::fd() const
{
    return _fd;
}

/**
 * @brief 关闭套接字的写端。
 * 
 * 调用系统的shutdown函数关闭套接字的写端，
 * 如果失败，会打印错误信息。
 */
void Socket::shutDownWrite()
{
    int ret = shutdown(_fd, SHUT_WR);
    if(ret)
    {
        perror("shutdown");
        return;
    }
}

