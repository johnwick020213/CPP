/**
 * Project Untitled
 */


#include "Consumer.h"
#include"TaskQueue.h"
#include<unistd.h>
#include<iostream>

using std::cout;
using std::endl;
/**
 * Consumer implementation
 */


/**
 * @param taskQue
 * @return void
 */
void Consumer::consume(TaskQueue & taskQue) {
    int cnt=20;
    while(cnt--)
    {
        int number=taskQue.pop();
        cout<<"Consumer conseme  "<<number<<endl;
        sleep(1);
    }
}
