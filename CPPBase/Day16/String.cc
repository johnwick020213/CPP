#include<iostream>
#include<cstring>
#include <cstdlib>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String &rhs);
    String(String &&rhs);
    String & operator=(String &&rhs);
	String &operator=(const String &rhs);
	~String();
	void print();
    size_t length() const;
    const char * c_str() const;

private:
	char * _pstr;
};

size_t String::length() const
{
    size_t len=0;
    char*p=_pstr;
    //cout<<"测试信息："<<*(p+1)<<endl;
    while(*(p+len)!='\0')
    {
        len++;
    }
    return len;
}

const char * String::c_str() const
{
    return _pstr;
}

String::String()
: _pstr(new char[1])
{
    strcpy(_pstr,"");
}

String::String(const char *ptr)
:_pstr(new char[strlen(ptr)+1]())
{
    strcpy(_pstr,ptr);
    cout<<"String(const char *ptr)"<<endl;
    cout<<_pstr<<endl;
}

String::String(const String &rhs)
:_pstr(new char[strlen(rhs._pstr)+1])
{
    strcpy(_pstr,rhs._pstr);
    cout<<"String(const String &rhs)"<<endl;
}

String& String::operator=(const String &rhs)
{
    if(this!=&rhs)
    {
        delete []_pstr;
        _pstr=new char[strlen(rhs._pstr)+1];
        strcpy(_pstr,rhs._pstr);
    }
    cout<<"String::operator=(const String &rhs)"<<endl;
    return *this;
}

String::~String()
{
    delete []_pstr;

}
String::String(String && rhs)
    :_pstr(rhs._pstr)
{
    cout<<"移动构造"<<endl;
    rhs._pstr=nullptr;
}

String & String::operator=(String&&rhs)
{
    if(this!=&rhs)
    {
       delete []_pstr;
       _pstr=rhs._pstr;
       rhs._pstr=nullptr;
       cout<<"移动复制"<<endl; 
    }
    return *this;
}
void String::print()
{
    cout<<"字符串:"<<_pstr<<endl;
}

int main()
{
   String str1;
   str1="nihao";
	//String str2 = "Hello,world";
	//String str3("wangdao");
	
    str1.print();
    //str2.print();		
	//str3.print();	
	
	return 0;
}
