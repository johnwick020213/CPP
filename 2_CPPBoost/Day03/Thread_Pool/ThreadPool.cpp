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

#include"ThreadPool.h"
#include"Task.h"

#include<iostream>

using std::cout;
using std::endl;

ThreadPool::ThreadPool(size_t threadNum,size_t queSize)
    :_threadNum(threadNum)
     ,_threads()
     ,_queSize(queSize)
     ,_taskQue(_queSize)
     ,_isExit(false)
{}

ThreadPool::~ThreadPool(){}

void ThreadPool::start()
{
    //需要创建出线程（线程创建出来之后需要执行线程入口函数）
    for(size_t idx=0;idx!=_threadNum;++idx)
    {
        _threads.push_back(thread(&ThreadPool::doTask,this));
    }
}

void ThreadPool::stop()
{
    while(!_taskQue.empty())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    _isExit=true;

    for(auto &th:_threads)
    {
        th.join();
    }
}

void ThreadPool::addTask(Task*ptask)
{
    if(ptask)
    {
        _taskQue.push(ptask);
    }
}

Task *ThreadPool::getTask()
{
    return _taskQue.pop();
}

void ThreadPool::doTask()
{
    while(!_isExit)
    {
        Task *ptask=getTask();
        if(ptask)
        {
            ptask->process();
        }
        else
        {
            cout<<"ptask==nullptr"<<endl;
        }
    }
    
}



