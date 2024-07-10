#include <iostream>
#include<cstring>
using std::cout;
using std::endl;

class Person
{
public:
    Person(){};
    Person(const char *name,int age);
    ~Person();
    Person(const Person &p);
    Person &operator=(const Person &rhs);

    virtual
        void display();

private:
    char* _name;
    int _age;
};

class Employee
:public Person
{
public:
    Employee(){nums++;}
    Employee(const char*name,int age,const char*department,int salary);
    ~Employee();
    
    Employee(const Employee& em);
    Employee&operator=(const Employee& em);
    friend
    float salaryAvg();
private:
    char* _department;
    int _salary;
    static long int sum;
    static int nums;
};


Person::Person(const char *name,int age)
    :_name(new char[strlen(name)+1])
     ,_age(age)
{
    strcpy(_name,name);
}

Person::~Person()
{
    if(_name)
    {
        cout<<"~Person()"<<endl;
        delete []_name;
    }
    else
    {
        cout<<"没有Person需要销毁"<<endl;
    }
}


Person::Person(const Person &p)
:_name(new char[strlen(p._name)+1])
    ,_age(p._age)
{
    strcpy(_name,p._name);
}

Person& Person::operator=(const Person&rhs)
{
    if(this!=&rhs)
    {
        delete []_name;
        new char [strlen(rhs._name)+1];
        strcpy(this->_name,rhs._name);
        this->_age=rhs._age;
    }
    return *this;
}

void Person::display()
{
    cout<<"姓名："<<_name<<" 年龄："<<_age<<endl;
}


Employee::Employee(const char*name,int age,const char*department,int salary)
:Person(name,age)
    ,_department(new char[strlen(department)+1])
    ,_salary(salary)
{   
    nums++;
    sum+=_salary;
    strcpy(_department,department);
}

Employee::~Employee()
{
    if(_department)
    {
        cout<<"~Employee()"<<endl;
        delete []_department;
        nums--;
        sum-=_salary;
    }
    else
    {
        cout<<"没有Department需要销毁"<<endl;
    }
}

Employee::Employee(const Employee& em)
    :Person(em)
     ,_department(new char[strlen(em._department)+1])
     ,_salary(em._salary)
    {
        nums++;
        sum+=_salary;
        strcpy(_department,em._department);
    }

Employee& Employee::operator=(const Employee&rhs)
{
    if(this!=&rhs)
    {
        sum-=_salary;
        delete []_department;
        new char[strlen(rhs._department)+1];
        strcpy(this->_department,rhs._department);
        this->_salary=rhs._salary;
        sum+=_salary;
    }
    return *this;
}

float salaryAvg()
{
    cout<<Employee::nums<<" "<<Employee::sum<<endl;
    return  Employee::sum/Employee::nums;
}

long int Employee::sum=0;
int Employee::nums=0;

int main()
{
    Employee em1("ganbo",22,"CEO",10000);
    Employee em2=em1;
    cout<<salaryAvg()<<endl;
    return 0;
}

