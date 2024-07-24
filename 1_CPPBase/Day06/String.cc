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
}

String::String(const String &rhs)
:_pstr(new char[strlen(rhs._pstr)+1])
{
    strcpy(_pstr,rhs._pstr);
}

String& String::operator=(const String &rhs)
{
    if(this!=&rhs)
    {
        delete []_pstr;
        _pstr=new char[strlen(rhs._pstr)+1];
        strcpy(_pstr,rhs._pstr);
    }
    return *this;
}

String::~String()
{
    delete []_pstr;

}

void String::print()
{
    cout<<"字符串:"<<_pstr<<endl;
}

int main()
{
	String str1;
	str1.print();
	

	String str2 = "Hello,world";
	String str3("wangdao");
	
    cout<<"长度："<<str2.length()<<endl;

    str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
	
	return 0;
}
