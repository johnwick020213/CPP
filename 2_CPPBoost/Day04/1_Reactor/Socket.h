/**
 * @file Socket.h
 * @author johnwick
 * @brief Socket类的头文件。
 *
 * 该文件定义了Socket类，封装了套接字的基本操作。
 * Socket类继承自NonCopyable类，以防止套接字对象的复制。
 * 提供了创建、销毁和关闭写端的功能。
 */
#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "NonCopyable.h"

/**
 * @class Socket
 * @brief 表示一个套接字的类。
 *
 * Socket类封装了一个套接字描述符，并提供了管理套接字生命周期的方法，包括创建、销毁和关闭套接字的写端。该类继承自NonCopyable以防止复制。
 */
class Socket : NonCopyable {
public:
    /**
     * @brief 默认构造函数。
     *
     * 用无效的文件描述符初始化一个新的套接字。
     */
    Socket();

    /**
     * @brief 带文件描述符的构造函数。
     *
     * 用给定的文件描述符初始化一个新的套接字。
     * @param fd 文件描述符。
     */
    explicit Socket(int fd);

    /**
     * @brief 析构函数。
     *
     * 销毁套接字对象，关闭文件描述符。
     */
    ~Socket();

    /**
     * @brief 获取文件描述符。
     *
     * @return 文件描述符。
     */
    int fd() const;

    /**
     * @brief 关闭写端。
     *
     * 关闭套接字的写端以禁止发送数据。
     */
    void shutDownWrite();

private:
    int _fd; ///< 套接字的文件描述符。
};

#endif

