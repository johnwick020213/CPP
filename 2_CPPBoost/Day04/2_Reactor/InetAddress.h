/**
 * @file InetAddress.h
 * @author johnwick
 * @brief InetAddress类的头文件。
 *
 * 该文件定义了InetAddress类，封装了IP地址和端口的相关操作。
 * 提供了从IP地址和端口创建、从sockaddr_in结构体创建、获取IP地址、获取端口和获取sockaddr_in指针的功能。
 */

#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__

#include <arpa/inet.h>
#include <string>

using std::string;

/**
 * @class InetAddress
 * @brief 表示一个网络地址的类。
 *
 * InetAddress类封装了IP地址和端口，提供了相应的操作方法。
 */
class InetAddress {
public:
    /**
     * @brief 使用IP地址和端口构造InetAddress对象。
     *
     * @param ip IP地址。
     * @param port 端口号。
     */
    InetAddress(const string &ip, unsigned short port);

    /**
     * @brief 使用sockaddr_in结构体构造InetAddress对象。
     *
     * @param addr sockaddr_in结构体。
     */
    InetAddress(const struct sockaddr_in &addr);

    /**
     * @brief 析构函数。
     *
     * 销毁InetAddress对象。
     */
    ~InetAddress();

    /**
     * @brief 获取IP地址。
     *
     * @return IP地址字符串。
     */
    string ip() const;

    /**
     * @brief 获取端口号。
     *
     * @return 端口号。
     */
    unsigned short port() const;

    /**
     * @brief 获取sockaddr_in结构体指针。
     *
     * @return 指向sockaddr_in结构体的指针。
     */
    const struct sockaddr_in *getInetAddrPtr() const;

private:
    struct sockaddr_in _addr; ///< 存储IP地址和端口的sockaddr_in结构体。
};

#endif // __INETADDRESS_H__

