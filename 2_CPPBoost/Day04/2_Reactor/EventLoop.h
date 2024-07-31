/**
 * @file EventLoop.h
 * @brief 声明EventLoop类，处理事件循环
 */

#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include <sys/epoll.h>
#include <vector>
#include <map>
#include <memory>

using std::vector;
using std::map;
using std::shared_ptr;

class Acceptor;  // 前向声明
class TcpConnection;

/**
 * @brief EventLoop类，处理事件循环
 */
class EventLoop
{
    using TcpConnectionPtr = shared_ptr<TcpConnection>;
public:
    /**
     * @brief 构造函数，初始化EventLoop对象
     * @param accptor 传入的Acceptor对象
     */
    EventLoop(Acceptor &accptor);

    /**
     * @brief 析构函数，销毁EventLoop对象
     */
    ~EventLoop();

    /**
     * @brief 开始事件循环
     */
    void loop();

    /**
     * @brief 停止事件循环
     */
    void unloop();

    /**
     * @brief 封装epoll_wait函数，等待事件发生
     */
    void waitEpollFd();

    /**
     * @brief 处理新的连接
     */
    void handleNewConnection();

    /**
     * @brief 处理老的连接上的数据
     * @param fd 文件描述符
     */
    void handleMessage(int fd);

    /**
     * @brief 封装epoll_create函数，创建epoll文件描述符
     * @return 返回创建的epoll文件描述符
     */
    int createEpollFd();

    /**
     * @brief 将文件描述符放在红黑树上进行监听
     * @param fd 文件描述符
     */
    void addEpollReadFd(int fd);

    /**
     * @brief 将文件描述符从红黑树上取消监听
     * @param fd 文件描述符
     */
    void delEpollReadFd(int fd);

private:
    int _epfd;  ///< 由epoll_create创建的文件描述符
    vector<struct epoll_event> _evtList;  ///< 交给epoll_wait的第二个参数，存放就绪的文件描述符
    bool _isLooping;  ///< 标识循环是否在运行
    Acceptor &_acceptor;  ///< 获取Acceptor类型的引用，目的是为了调用其中的accept函数
    map<int, TcpConnectionPtr> _conns;  ///< 存放文件描述符与TcpConnection键值对
};

#endif /* __EVENTLOOP_H__ */

