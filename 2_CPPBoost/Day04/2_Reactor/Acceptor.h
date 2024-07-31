/**
 * @file Acceptor.h
 * @author johnwick
 * @brief Acceptor类的头文件，用于定义Acceptor类及其成员函数。
 * 
 * 这个文件包含Acceptor类的定义，该类封装了服务器端的套接字接收操作，
 * 提供了设置地址复用，绑定，监听和接收连接的功能。
 */ 

#ifndef __ACCEPTOR_H__
#define __ACCEPTOR_H__

#include"Socket.h"
#include "InetAddress.h"
#include <string>

using std::string;

/**
 * @class Acceptor
 * @brief 封装服务器端和套接字接收操作的类。
 * 
 * Acceptor类提供了初始化服务器端套接字，设置地址复用，绑定，监听和接收连接的功能。
 */ 
class Acceptor
{
public:
    /**
    * @class Acceptor
    * @brief 构造函数，使用IP地址和端口初始化Acceptor对象。
    * @param ip IP地址。
    * @param port 端口号。
    */ 
    Acceptor(const string &ip,unsigned short port);

    /**
     * @brief 析构函数，销毁Acceptor对象。
     */ 
    ~Acceptor();

    /**
     * @brief 准备服务器套接字，包括设置地址复用，绑定和监听。
     */ 
    void ready();
    
    /**
     * @brief 接收一个新的连接。
     * @return 新的套接字文件描述符，失败返回-1。
     */ 
    int accept();

    /**
     * @brief 获取服务器端套接字的文件描述符。
     * @return 套接字文件描述符。
     */ 
    int fd() const;
private:
    /**
     * @brief 设置地址复用。
     */ 
    void setReuseAddr();

    /**
     * @brief 设置端口复用。
     */ 
    void setReusePort();
    
    /**
     * @brief 绑定套接字到指定的IP地址和端口。
     */ 
    void bind();

    /**
     * @brief 监听套接字，准备接收连接。
     */ 
    void listen();

private:
    Socket _sock;///<封装的套接字对象。
    InetAddress _addr;///<封装的地址对象。
};

   

#endif 

