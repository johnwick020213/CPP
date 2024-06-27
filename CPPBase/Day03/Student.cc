#include <iostream>
#include<cstring>


using std::cout;
using std::endl;

class Student{
public:
    Student(int id,double height=0,const char* name="",double score=0)
        :_id(id),_height(height),_score(score)
    {
        strncpy(_name,name,sizeof(name)-1);
        _name[sizeof(_name)-1]='\0';
        cout<<"初始化成功"<<endl;
    }

    void print(){
        cout<<"ID:"<<_id
            <<" height:"<<_height
            <<" name:"<<_name
            <<" socre:"<<_score<<endl;
    }
private:
    int _id;
    double _height;
    char _name[20];
    double _score;
};


int main()
{
    Student s(1,185,"ganbo",100);
    s.print();
    return 0;
}

