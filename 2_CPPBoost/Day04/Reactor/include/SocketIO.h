#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <iostream>
#include <string>

class SocketIO
{
public:
    explicit SocketIO(int fd);
    ~SocketIO();
    int readn(char *buf,int len);
    int readLine(char *buf,int len);
    int writen(const char*buf,int len);

private:
    int _fd;
};

   

#endif 

