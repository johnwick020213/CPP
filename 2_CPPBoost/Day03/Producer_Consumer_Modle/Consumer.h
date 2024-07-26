/**
 * Project Untitled
 */


#ifndef _CONSUMER_H
#define _CONSUMER_H

#include"TaskQueue.h"

class Consumer {
public: 
    
/**
 * @param taskQue
 */
void consume(TaskQueue & taskQue);
};

#endif //_CONSUMER_H
