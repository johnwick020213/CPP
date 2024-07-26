/**
 * Project Untitled
 */


#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H


#include<iostream>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;

class TaskQueue {
public: 
    
/**
 * @param capa
 */
TaskQueue(size_t capa);
    
/**
 * @param value
 */
void push(const int & value);
    
int pop();
    
bool full();
    
bool empty();
    
~TaskQueue();
private: 
    size_t _capacity;
    queue<int> _que;
    mutex _mutex;
    condition_variable _notEmpty;
    condition_variable _notFull;
};

#endif //_TASKQUEUE_H
