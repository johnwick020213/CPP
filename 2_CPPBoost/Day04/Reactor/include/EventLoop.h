#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include <sys/epoll.h>
#include <vector>
#include<map>
#include<memory>
#include<functional>
#include<mutex>

using std::vector;
using std::map;
using std::shared_ptr;
using std::function;
using std::mutex;
using std::lock_guard;

class Acceptor;
class TcpConnection;

using TcpConnectionPtr=shared_ptr<TcpConnection>;
using TcpConnectionCallback=function<void(const TcpConnectionPtr &)>;
using Functors=function<void()>;

class EventLoop
{
    public:
        EventLoop(Acceptor &acceptor);
        ~EventLoop();

        //是否在循环
        void loop();
        void unloop();

        //封装epoll_wait
        void waitEpollFd();

        //处理新的连接
        void handleNewConnection();

        //处理老连接上的数据
        void handleMessage(int fd);

        //封装epoll_create函数
        int createEpollFd();

        //将文件描述符放在红黑树上取消监听
        void addEpollReadFd(int fd);

        //将文件描述符从红黑树上取消监听
        void delEpollReadFd(int fd);

public:
        //三个回调函数注册
        void setNewConnectionCallback(TcpConnectionCallback &&cb);
        void setMessageCallback(TcpConnectionCallback &&cb);
        void setCloseCallback(TcpConnectionCallback &&cb);

        //创建用于通信的文件描述符
        int createEventFd();
        void handleRead();
        void wakeup();
        //遍历vector<Functors>
        void doPengdingFuntors();
        void runInLoop(Functors &&cb);

private:
        int _epfd;//有epoll_create创建的文件描述符
        vector<Functors> _pendings;//存放的是多个要执行的“任务”
        mutex _mutex;

};


   

#endif 

