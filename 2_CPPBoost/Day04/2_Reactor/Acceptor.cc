/**
 * @file Acceptor.cpp
 * @author johnwick
 * @brief Acceptor类的实现文件，提供Acceptor类的成员函数定义。
 */

#include "Acceptor.h"
#include <stdio.h>

/**
 * @brief 构造函数，使用IP地址和端口初始化Acceptor对象。
 * @param ip IP地址。
 * @param port 端口号。
 */
Acceptor::Acceptor(const string &ip, unsigned short port)
: _sock()
, _addr(ip, port)
{
}

/**
 * @brief 析构函数，销毁Acceptor对象。
 */
Acceptor::~Acceptor()
{

}

/**
 * @brief 准备服务器端套接字，包括设置地址复用、绑定和监听。
 */
void Acceptor::ready()
{
    setReuseAddr();
    setReusePort();
    bind();
    listen();
}

/**
 * @brief 设置地址复用选项。
 */
void Acceptor::setReuseAddr()
{
    int on = 1;
    int ret = setsockopt(_sock.fd(), SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if(ret)
    {
        perror("setsockopt");
        return;
    }
}

/**
 * @brief 设置端口复用选项。
 */
void Acceptor::setReusePort()
{
    int on = 1;
    int ret = setsockopt(_sock.fd(), SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on));
    if(-1 == ret)
    {
        perror("setsockopt");
        return;
    }
}

/**
 * @brief 绑定套接字到指定的IP地址和端口。
 */
void Acceptor::bind()
{
    int ret = ::bind(_sock.fd(), 
                     (struct sockaddr *)_addr.getInetAddrPtr(),
                     sizeof(struct sockaddr));
    if(-1 == ret)
    {
        perror("bind");
        return;
    }
}

/**
 * @brief 监听套接字，准备接受连接。
 */
void Acceptor::listen()
{
    int ret = ::listen(_sock.fd(), 128);
    if(-1 == ret)
    {
        perror("listen");
        return;
    }
}

/**
 * @brief 接受一个新的连接。
 * @return 新的套接字文件描述符，失败返回-1。
 */
int Acceptor::accept()
{
    int connfd = ::accept(_sock.fd(), nullptr, nullptr);
    if(-1 == connfd)
    {
        perror("accept");
        return -1;
    }
    return connfd;
}

/**
 * @brief 获取服务器端套接字的文件描述符。
 * @return 套接字文件描述符。
 */
int Acceptor::fd() const
{
    return _sock.fd();
}

