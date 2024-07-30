/**
 * @file SocketIO.h
 * @author johnwick
 * @brief SocketIO类的头文件，用于定义SocketIO类及其成员函数。
 * 
 * 这是文件包含SocketIO类的定义，该类封装了基于文件描述符的读写操作，
 * 提供了固定长度的数据，读一行数据和写固定长度的数据的功能。
 */ 

#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

/**
 * @class SocketIO
 * @brief 封装基于文件描述符的读写操作的类。
 * 
 * SocketIO类提供了三个主要的功能：
 * 1.读指定长度的数据。
 * 2.读一行数据。
 * 3.写指定长度的数据。
 */ 
class SocketIO
{
public:
    /**
     * @brief 构造函数，使用文件描述符初始化SocketIO对象。
     * @param fd 文件描述符。
     */ 
    explicit SocketIO(int fd);

    /**
     * @brief 析构函数，销毁SocketIO对象。
     */ 
    ~SocketIO();

    /**
     * @brief 读取指定长度的数据。
     * @param buf 存储读取数据的缓冲区。
     * @param len 读取数据的长度。
     * @return 实际读取的数据长度，失败返回-1。
     */
    int readn(char*buf,int len);

    /**
     * @brief 读取一行数据，以换行符结尾。
     * @param buf 存储读取数据的缓冲区。
     * @param len 缓冲区的最大长度。
     * @return 实际读取的数据长度，失败返回-1。
     */ 
    int readLine(char *buf,int len);

    /**
     * @brief 写入指定长度的数据。
     * @param buf 存储写入数据的缓冲区。
     * @param len 写入数据的长度
     * @return 实际写入的数据长度，失败返回-1。
     */ 
    int writen(const char *buf,int len);

private:
    int _fd;///<文件描述符，用于标识打开的文件。
};

   

#endif 

