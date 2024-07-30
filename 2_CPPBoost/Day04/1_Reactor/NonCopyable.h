/**
 * @file NonCopyable.h
 * @author johnwick
 * @brief 定义一个禁止复制和赋值操作的基类
 *
 * 这个文件包含了NonCopyable类的定义，该类用于禁止其派生类的复制和赋值操作。
 */

#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

/**
 * @brief 不允许复制或者赋值的基类
 * 
 * 这个类用于禁止其派生类的复制和赋值操作。
 */
class NonCopyable
{
protected:
    /**
     * @brief 构造函数
     * 
     * 定义为protected以防止直接实例化。
     */
    NonCopyable()
    {
    }

    /**
     * @brief 析构函数
     * 
     * 定义为protected以防止直接销毁对象。
     */
    ~NonCopyable()
    {
    }

    /**
     * @brief 禁用复制构造函数
     * 
     * 将复制构造函数删除，以防止对象被复制。
     */
    NonCopyable(const NonCopyable &) = delete;

    /**
     * @brief 禁用赋值操作符
     * 
     * 将赋值操作符删除，以防止对象被赋值。
     */
    NonCopyable &operator=(const NonCopyable &) = delete;
};

#endif // __NONCOPYABLE_H__

