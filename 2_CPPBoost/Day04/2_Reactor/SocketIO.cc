/**
 * @file SocketIO.cpp
 * @author johnwick
 * @brief SocketIO类的实现文件，提供SocketIO类的成员函数定义。
 */

#include "SocketIO.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

/**
 * @brief 构造函数，使用文件描述符初始化SocketIO对象。
 * @param fd 文件描述符。
 */
SocketIO::SocketIO(int fd)
: _fd(fd)
{

}

/**
 * @brief 析构函数，销毁SocketIO对象。
 */
SocketIO::~SocketIO()
{
    /* close(_fd); */
}

/**
 * @brief 读取指定长度的数据。
 * @param buf 存储读取数据的缓冲区。
 * @param len 读取数据的长度。
 * @return 实际读取的数据长度，失败返回-1。
 * 
 * 该函数会读取指定长度的数据，直到读取到len个字节的数据或遇到错误或EOF。
 */
int SocketIO::readn(char *buf, int len)
{
    int left = len;
    char *pstr = buf;
    int ret = 0;

    while(left > 0)
    {
        ret = read(_fd, pstr, left);
        if(-1 == ret && errno == EINTR)
        {
            continue;
        }
        else if(-1 == ret)
        {
            perror("read error -1");
            return -1;
        }
        else if(0 == ret)
        {
            break;
        }
        else
        {
            pstr += ret;
            left -= ret;
        }
    }

    return len - left;
}

/**
 * @brief 读取一行数据，以换行符结尾。
 * @param buf 存储读取数据的缓冲区。
 * @param len 缓冲区的最大长度。
 * @return 实际读取的数据长度，失败返回-1。
 * 
 * 该函数会读取一行数据，直到遇到换行符或读取到len-1个字节的数据。
 * 读取到的数据以'\0'结尾。
 */
int SocketIO::readLine(char *buf, int len)
{
    int left = len - 1;
    char *pstr = buf;
    int ret = 0, total = 0;

    while(left > 0)
    {
        // MSG_PEEK不会将缓冲区中的数据进行清空, 只会进行拷贝操作
        ret = recv(_fd, pstr, left, MSG_PEEK);
        if(-1 == ret && errno == EINTR)
        {
            continue;
        }
        else if(-1 == ret)
        {
            perror("readLine error -1");
            return -1;
        }
        else if(0 == ret)
        {
            break;
        }
        else
        {
            for(int idx = 0; idx < ret; ++idx)
            {
                if(pstr[idx] == '\n')
                {
                    int sz = idx + 1;
                    readn(pstr, sz);
                    pstr += sz;
                    *pstr = '\0'; // C风格字符串以'\0'结尾

                    return total + sz;
                }
            }

            readn(pstr, ret); // 从内核态拷贝到用户态
            total += ret;
            pstr += ret;
            left -= ret;
        }
    }
    *pstr = '\0';

    return total - left;
}

/**
 * @brief 写入指定长度的数据。
 * @param buf 存储要写入数据的缓冲区。
 * @param len 写入数据的长度。
 * @return 实际写入的数据长度，失败返回-1。
 * 
 * 该函数会写入指定长度的数据，直到写入len个字节的数据或遇到错误。
 */
int SocketIO::writen(const char *buf, int len)
{
    int left = len;
    const char *pstr = buf;
    int ret = 0;

    while(left > 0)
    {
        ret = write(_fd, pstr, left);
        if(-1 == ret && errno == EINTR)
        {
            continue;
        }
        else if(-1 == ret)
        {
            perror("writen error -1");
            return -1;
        }
        else if(0 == ret)
        {
            break;
        }
        else
        {
            pstr += ret;
            left -= ret;
        }
    }
    return len - left;
}

