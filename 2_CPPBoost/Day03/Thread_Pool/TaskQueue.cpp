 /* @file main.cpp */
 /* @brief 简要说明文件的功能和内容。 */
 
 /* 详细描述文件的功能、用途和实现细节。 */
 
 /* @note 注意事项或其他需要强调的信息。 */
 
 /* @version 1.0 */
 /* @date 2024-07-25 */
 
 /* @bug 目前已知的Bug列表。 */
 /* @warning 警告信息，如可能的误用。 */
 
 /* @author 作者名字 */
 /* @copyright 版权声明 */

#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t capa)
: _capacity(capa)
, _que()
, _mutex()
, _notEmpty()
, _notFull()
{

}

TaskQueue::~TaskQueue()
{

}

//添加任务与获取任务
void TaskQueue::push(ElemType ptask)
{
    unique_lock<mutex> ul(_mutex);

    while(full())
    {
        //上半部:解锁、睡眠
        //下半部:被唤醒、上锁、返回
        _notFull.wait(ul);
    }
    //如果不是满的,就可以生产数据，就可以唤醒消费者线程
    _que.push(ptask);
    _notEmpty.notify_one();
}

ElemType TaskQueue::pop()
{
    unique_lock<mutex> ul(_mutex);

    while(empty())
    {
        //如果是空的，就睡眠
        _notEmpty.wait(ul);
    }
    //如果不空，获取数据，唤醒生产者
    ElemType tmp  = _que.front();
    _que.pop();
    _notFull.notify_one();

    return tmp;
}

//判空与判满
bool TaskQueue::empty() const
{
    return 0 == _que.size();
}

bool TaskQueue::full() const
{
    return _capacity == _que.size();
}

