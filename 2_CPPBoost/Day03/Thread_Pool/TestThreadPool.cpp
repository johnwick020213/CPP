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

#include "Task.h"
#include "ThreadPool.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class MyTask
: public Task
{
public:
    void process() override
    {
        //MyTask到底执行什么任务
        //(需要根据具体的业务逻辑添加任务)
        ::srand(::clock());//种随机种子
        int number = ::rand() % 100;//产生随机数
        cout << "MyTask number = " << number << endl;
    }
};

//1、现在只执行了12个任务，程序就结束了？(任务没有达到20个)
//思考：现在到底添加了多少个任务?
//通过打印之后，发现任务确实添加了20个，因为cnt的打印是20次
//
//问题一：添加了20次的任务，但是任务没有执行完，程序就退出了?
//原因：主线程与工作线程都在执行，但是有可能主线程将任务添加
//完毕之后，会继续执行stop函数，将标志位_isExit设置为了true，
//此时子线程在执行while循环的时候，不能进入到while循环中，
//那么就会出现任务没有执行完，程序就退出来了
//
//解决方案：在stop函数中添加代码，只要任务执行不完，就让
//主线程睡眠
//
//问题二：任务有时候可以执行完，但是发现程序好像没有退出来?
void test()
{
    unique_ptr<Task> ptask(new MyTask());
    //创建线程池的对象
    ThreadPool pool(4, 10);

    //启动线程池
    pool.start();

    //添加任务
    int cnt = 20;
    while(cnt--)
    {
        pool.addTask(ptask.get());
        cout << "cnt = " << cnt << endl;
    }

    //关闭线程池
    pool.stop();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}


