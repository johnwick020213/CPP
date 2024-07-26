/**
 * Project Untitled
 */


#include "TaskQueue.h"

/**
 * TaskQueue implementation
 */


/**
 * @param capa
 */
TaskQueue::TaskQueue(size_t capa) 
:_capacity(capa)
    ,_que()
    ,_mutex()
    ,_notEmpty()
    ,_notFull()
{
    
}

/**
 * @param value
 */
void TaskQueue::push(const int & value) {
    //上锁
    unique_lock<mutex> ul(_mutex);
    /* cout<<value<<endl; */
    //判断任务队列是不是满的
    while(full())
    {
        //如果是满的，生产者线程需要在对应的条件变量上睡眠
        //上半部分：解锁，睡眠
        //下班部分：被唤醒，上锁，返回
        _notFull.wait(ul);
    }

    //如果不是满的，就可以生产数据，就可以唤醒消费者线程
    _que.push(value);
    /* cout<<"测试信息"<<_que.front()<<endl; */
    _notEmpty.notify_one();
    //利用栈对象生命周期解锁，不用手动解锁
}

/**
 * @return int
 */
int TaskQueue::pop() {
    //上锁
    unique_lock<mutex> ul(_mutex);
    //判空
    while(empty())
    {
        //如果是空就睡觉
        _notEmpty.wait(ul);
    }
    //如果不空，获取数据，唤醒生产者
    int tmp=_que.front();
    _que.pop();
    _notFull.notify_one();

    return tmp;
}

/**
 * @return bool
 */
bool TaskQueue::empty() {
    return 0==_que.size();
}

/**
 * @return bool
 */
bool TaskQueue::full() {
    return _capacity==_que.size();
}

TaskQueue::~TaskQueue() {

}
