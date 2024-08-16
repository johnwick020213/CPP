#ifndef __SOCKET_H_
#define __SOCKET_H_

#include <iostream>
#include <string>
#include"NonCopyable.h"
class Socket
:NonCopyable
{
    public:
        Socket();
        explicit Socket(int fd);
        ~Socket();
        int fd() const;
        void shutDownWrite();

    private:
        int _fd;
};
   

#endif 

