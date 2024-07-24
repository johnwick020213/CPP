#ifndef __Line_HH__
#define __Line_HH__


class Line{
public:
    Line(int x1, int y1, int x2, int y2);
    ~Line();

    //提供给客户使用的功能
    void printLine() const;//打印Line对象的信息
private:
    class LineImpl;//类的前向声明
    LineImpl * _pimpl;
};



#endif

