
/**
 * @file EventLoop.cpp
 * @brief 实现事件循环的功能
 */

#include "EventLoop.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include <unistd.h>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

/**
 * @brief 构造函数，初始化EventLoop对象
 * @param accptor 传入的Acceptor对象
 */
EventLoop::EventLoop(Acceptor &accptor)
: _epfd(createEpollFd())
, _evtList(1024)
, _isLooping(false)
, _acceptor(accptor)
{
    //需要将listenfd放在红黑树上进行监听
    int listenfd = _acceptor.fd();
    addEpollReadFd(listenfd);
}

/**
 * @brief 析构函数，关闭epoll文件描述符
 */
EventLoop::~EventLoop()
{
    close(_epfd);
}

/**
 * @brief 开始事件循环
 */
void EventLoop::loop()
{
    _isLooping = true;
    while(_isLooping)
    {
        waitEpollFd();
    }
}

/**
 * @brief 停止事件循环
 */
void EventLoop::unloop()
{
    _isLooping = false;
}

/**
 * @brief 封装epoll_wait函数，等待事件发生
 */
void EventLoop::waitEpollFd()
{
    //获取vector的第一个元素的首地址
    int nready = 0;
    do
    {
        nready = ::epoll_wait(_epfd, &*_evtList.begin(), _evtList.size(), 3000);
    }while(-1 == nready && errno == EINTR);

    if(-1 == nready)
    {
        cerr << "-1 == nready " << endl;
        return;
    }
    else if(0 == nready)
    {
        cout << ">>epoll_wait timeout!!!" << endl;
    }
    else
    {
        //为了防止文件描述符的数目超过1024，我们可以手动扩容
        if(nready == (int)_evtList.size())
        {
            _evtList.resize(2 * nready);
        }

        for(int idx = 0; idx < nready; ++idx)
        {
            int fd = _evtList[idx].data.fd;
            int listenfd = _acceptor.fd();

            if(fd == listenfd)
            {
                handleNewConnection();//处理新的连接请求
            }
            else
            {
                handleMessage(fd);//处理老的连接
            }
        }
    }
}

/**
 * @brief 处理新的连接
 */
void EventLoop::handleNewConnection()
{
    //如果connfd是正常的，就表明三次握手完全成功
    int connfd = _acceptor.accept();
    if(connfd < 0)
    {
        perror("handleNewConnection");
        return;
    }

    //将文件描述符connfd放在红黑树上进行监听
    addEpollReadFd(connfd);

    //三次握手建立成功，就可以创建出TcpConnection连接
    TcpConnectionPtr con(new TcpConnection(connfd));

    //存储文件描述符connfd与连接TcpConnection的键值对
    /* _conns.insert({connfd, con}); */
    _conns[connfd] = con;
}

/**
 * @brief 处理老的连接上的数据
 * @param fd 文件描述符
 */
void EventLoop::handleMessage(int fd)
{
    auto it = _conns.find(fd);
    if(it != _conns.end())
    {
        //接收客户端的数据
        string msg = it->second->receive();
        cout << ">>recv msg from client: " << msg << endl;

        //做业务逻辑的处理

        //业务逻辑处理完毕之后，需要将数据msg发给客户端
        it->second->send(msg);
    }
    else
    {
        cout << "连接是不存在的" << endl;
        return;
    }
}

/**
 * @brief 封装epoll_create函数，创建epoll文件描述符
 * @return 返回创建的epoll文件描述符
 */
int EventLoop::createEpollFd()
{
    int fd = ::epoll_create(1);
    if(fd < 0)
    {
        perror("createEpollFd");
        return -1;
    }
    return fd;
}

/**
 * @brief 将文件描述符放在红黑树上进行监听
 * @param fd 文件描述符
 */
void EventLoop::addEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.events = EPOLLIN;
    evt.data.fd = fd;

    int ret = ::epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &evt);
    if(ret < 0)
    {
        perror("addEpollReadFd");
        return;
    }
}

/**
 * @brief 将文件描述符从红黑树上取消监听
 * @param fd 文件描述符
 */
void EventLoop::delEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.events = EPOLLIN;
    evt.data.fd = fd;

    int ret = ::epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &evt);
    if(ret < 0)
    {
        perror("delEpollReadFd");
        return;
    }
}

