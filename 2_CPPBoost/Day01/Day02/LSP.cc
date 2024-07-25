#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

class User
{
public:
    User(const string name)
        :_name(name)
    {
        cout<<"User()"<<endl;
    }

    void consume(float delta)
    {
        cout<<"consume"<<endl;
        _score+=delta;
        cout<<">>"<<_name<<"消费："<<delta<<" 当前积分："<<_score<<endl;
    }

protected:
    string _name;
    float _score;
};

class Vipuser
:public User
{
public:
    Vipuser(const string &name)
        :User(name)
         ,_discount(1)
    {
        cout<<"Vipuser()"<<endl;
    }
    
    void consume2(float delta)
    {
        cout<<"consume2()"<<endl;
        float tmp=delta*_discount;
        _score+=tmp;

        if(_score>1000&&_score<9000)
        {
            _discount=0.9;
        }

        cout<<">>"<<_name<<"消费"<<tmp<<endl;
    }
private:
    float _discount;
};

int main()
{
     User user("lili");
    user.consume(2000);
    user.consume(2000);
    user.consume(2000);
    user.consume(2000);

    cout <<endl;
    Vipuser vip("lucy");
    vip.consume(2000);//隐藏
    vip.consume(2000);//隐藏
    vip.consume2(2000);
    vip.consume2(2000);//增加了自己的个性
    return 0;
}

