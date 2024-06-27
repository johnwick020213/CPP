#include <iostream>
#include<cstring>


using std::cout;
using std::endl;

class Student{
public:
    Student(int id,double height,const char* name,double score)
        :_id(id),_height(height),_name(new char[strlen(name)+1]()),_score(score)
    {
        strcpy(_name,name);
        cout<<"初始化成功"<<endl;
    }
    
    ~Student()
    {
        if(_name){
            delete []_name;
            _name=nullptr;
            cout<<"已经销毁"<<endl;
        }
        cout<<"~Student()"<<endl;
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
    char* _name;
    double _score;
};


int main()
{
    Student s(1,185,"ganbo",100);
    s.print();
    s.~Student();
    return 0;
}

