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

#include<iostream>
#include"Producer.h"
#include"Consumer.h"
#include"TaskQueue.h"
#include<thread>


using namespace std;

int main(int argc,char *argv[])
{
    Producer pr;
    Consumer co;
    TaskQueue taskQue(10);

    //线程的入口函数使用的是值传递
    thread pro(&Producer::produce,&pr,std::ref(taskQue));
    thread con(&Consumer::consume,&co,std::ref(taskQue));

    pro.join();
    con.join();
    
    return 0;
}

