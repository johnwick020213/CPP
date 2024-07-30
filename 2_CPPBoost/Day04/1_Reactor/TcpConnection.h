

#ifndef HEADER_FILENAME_H
#define HEADER_FILENAME_H

#include"SocketIO.h"
#include"Socket.h"
#include"InetAddress.h" 
#include <string>

using std::string;

class TcpConnection
{
public:
    /**
     * @brief 构造函数，使用文件描述符初始化TcpConnection对象。
     * @param fd 文件描述符。
     */ 
    explicit TcpConnection(int fd);

    /**
     * @brief 析构函数，销毁TcpConnection对象。
     */ 
    ~TcpConnection();

    /**
     * @brief 发送消息。
     * @param msg 要发送的消息字符串。
     */ 
    void send(const string &msg);

    /**
     * @brief 接收消息。
     * @return 接收的消息字符串。
     */ 
    string receive();

    /**
     * @brief 获取连接的信息，便于调试。
     * @return 连接信息字符串。
     */ 
    string toString();
private:
    /**
     * @brief 获取本地地址。
     * @return 本地地址对象。
     */ 
    InetAddress getLocalAddr();

    /**
     * @brief 获取对端地址。
     * @return 对端地址对象。
     */ 
    InetAddress getPeerAddr();

private:
    SocketIO _sockIO;///<封装套接字IO对象。

    //为了调试而加入的三个数据成员
    Socket _sock;///<封装的套接字对象。
    InetAddress _localAddr;///<本地地址对象。
    InetAddress _peerAddr;///<对端地址对象。
};

   

#endif 

