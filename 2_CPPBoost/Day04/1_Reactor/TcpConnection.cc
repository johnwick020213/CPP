/**
 * @file TcpConnection.cpp
 * @brief 实现TcpConnection类的方法
 */

#include "TcpConnection.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;

/**
 * @brief 构造函数
 * @param fd 套接字文件描述符
 */
TcpConnection::TcpConnection(int fd)
: _sockIO(fd)
, _sock(fd)
, _localAddr(getLocalAddr())
, _peerAddr(getPeerAddr())
{

}

/**
 * @brief 析构函数
 */
TcpConnection::~TcpConnection()
{

}

/**
 * @brief 发送消息
 * @param msg 要发送的消息
 */
void TcpConnection::send(const string &msg)
{
    _sockIO.writen(msg.c_str(), msg.size());
}

/**
 * @brief 接收消息
 * @return 返回接收到的消息
 */
string TcpConnection::receive()
{
    char buff[65535] = {0};
    _sockIO.readLine(buff, sizeof(buff));

    return string(buff);
}

/**
 * @brief 获取连接的字符串表示
 * @return 返回连接的字符串表示
 */
string TcpConnection::toString()
{
    ostringstream oss;
    oss << _localAddr.ip() << ":"
        << _localAddr.port() << "---->"
        << _peerAddr.ip() << ":"
        << _peerAddr.port();

    return oss.str();
}

/**
 * @brief 获取本端的网络地址信息
 * @return 返回本端的网络地址信息
 */
InetAddress TcpConnection::getLocalAddr()
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    //获取本端地址的函数getsockname
    int ret = getsockname(_sock.fd(), (struct sockaddr *)&addr, &len);
    if(-1 == ret)
    {
        perror("getsockname");
    }

    return InetAddress(addr);
}

/**
 * @brief 获取对端的网络地址信息
 * @return 返回对端的网络地址信息
 */
InetAddress TcpConnection::getPeerAddr()
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    //获取对端地址的函数getpeername
    int ret = getpeername(_sock.fd(), (struct sockaddr *)&addr, &len);
    if(-1 == ret)
    {
        perror("getpeername");
    }

    return InetAddress(addr);
}

