#include <iostream>
#include<cstring>
using namespace std;

class String 
{
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	String &operator=(const String &);
	String &operator=(const char *);

	String &operator+=(const String &);
	String &operator+=(const char *);
	
	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;
	
	std::size_t size() const;
	const char* c_str() const;
	
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);
	
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

    void print();

private:
	char * _pstr;
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);

String::String()
{
    String::_pstr=new char[1];
    cout<<"String()"<<endl;
}

String::String(const char *p)
:_pstr(new char[strlen(p)+1])
{
    strcpy(_pstr,p);
    cout<<"String(const char*)"<<endl;
}

String::String(const String &rhs)
:_pstr(new char[strlen(rhs._pstr)+1])
{
    strcpy(String::_pstr,rhs._pstr);
    cout<<"String(const String &)"<<endl;
}

String::~String()
{
    delete []_pstr;
    String::_pstr=nullptr;
}

String& String::operator=(const String &rhs)
{
    cout<<"&operator=(const String&)"<<endl;
    if(this!=&rhs)
    {
        delete []_pstr;
        _pstr=new char[strlen(rhs._pstr)+1];
        strcpy(_pstr,rhs._pstr);
    }
    return *this;

}

String& String::operator=(const char *p)
{
    cout<<"&operator=(const char*)"<<endl;
    if(this->_pstr!=p)
    {
        delete []_pstr;
        _pstr=new char[strlen(p)+1];
        strcpy(_pstr,p);
    }
    return *this;

}

String& String::operator+=(const String &rhs)
{
    cout<<"&operator+=(cosnt String&)"<<endl;
    strcat(_pstr,rhs._pstr);
    return *this;
}

String& String::operator+=(const char*p)
{
    
    cout<<"&operator+=(cosnt char *)"<<endl;
    strcat(_pstr,p);
    return *this;
}

char &String::operator[](std::size_t index)
{
    cout<<"无const【】"<<endl;
    if(index>strlen(_pstr)-1)
    {
        cout<<"超出范围"<<endl;
        static char nullchar='\0';
        return nullchar;
    }else{
        char & c=_pstr[index];
        return c;
    }
}

const char& String::operator[](std::size_t indx) const
{
    cout<<"有const【】"<<endl;
     if(indx>strlen(_pstr)-1)
    {
        cout<<"超出范围"<<endl;
        static char  nullchar='\0';
        return nullchar;
    }else{
        cout<<"范围正确"<<endl;
        return _pstr[indx];
    }
}



std::size_t String::size() const
{
    return strlen(_pstr);
}

const char*String::c_str() const
{
    return _pstr;
}

bool operator==(const String&lhs,const String &rhs)
{
    if(strcmp(lhs.c_str(),rhs.c_str()))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator!=(const String&lhs,const String &rhs)
{
    if(strcmp(lhs.c_str(),rhs.c_str()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const String&lhs,const String &rhs)
{
    if(strcmp(lhs.c_str(),rhs.c_str())<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const String&lhs,const String &rhs)
{
    if(strcmp(lhs.c_str(),rhs.c_str())>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(const String&lhs,const String &rhs)
{
    if(strcmp(lhs.c_str(),rhs.c_str())<=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(const String&lhs,const String &rhs)
{
    if(strcmp(lhs.c_str(),rhs.c_str())>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os<<s.c_str();
    return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
    is>>s._pstr;
    return is;
}


String operator+(const String &lhs, const String &rhs)
{
    cout<<"operator+(const String &lhs, const String &rhs)"<<endl;
    String temp;
    temp+=lhs;
    temp+=rhs;

    return temp.c_str();
}

String operator+(const String &lhs, const char *p)
{
    cout<<"operator+(const String &lhs, const char *p)"<<endl;
    String temp;
    temp+=lhs;
    temp+=p;

    return temp.c_str();

}

String operator+(const char *p, const String &rhs)
{
    cout<<"operator+(const char *p, const String &rhs)"<<endl;
    String temp;
    temp+=p;
    temp+=rhs;

    return temp.c_str();

}



void String::print()
{
    cout<<"\""<<_pstr<<"\""<<endl;
}

int main()
{
    cout<<"1.____________________________________"<<endl;
    String str1;
    str1.print();

    cout<<"2.____________________________________"<<endl;
    const char*p="Hello,2";
    String str2(p);
    str2.print();

    cout<<"3.____________________________________"<<endl;
    const String &rhs=str2;
    String str3(rhs);
    str3.print();

    cout<<"4.____________________________________"<<endl;
    String str4;
    str4=str3;
    str4.print();

    cout<<"5.____________________________________"<<endl;
    String str5;
    str5=p;
    str5.print();

    cout<<"6.____________________________________"<<endl;
    String str6="world";
    str6+=rhs;
    str6.print();
    

    cout<<"7.____________________________________"<<endl;
    String str7="fk";
    str7+=p;
    str7.print();

    cout<<"8.____________________________________"<<endl;
    char &c=str7[1];
    cout<<c<<endl;
    c=str7[100];
    cout<<c<<endl;

    cout<<"9.____________________________________"<<endl;
    const String str9="nihao";
    cout<<str9[1]<<endl;
    cout<<str9[100]<<endl;
    
    cout<<"10.____________________________________"<<endl;
    cout<<str9.size()<<endl;
    cout<<str7.size()<<endl;
    cout<<str2.size()<<endl;

    cout<<"11.____________________________________"<<endl;
    cout<<str9.c_str()<<endl;
    
    cout<<"12.____________________________________"<<endl;
    cout<<(str3==str2)<<endl;


    cout<<"13.____________________________________"<<endl;
    cout<<str9<<endl;


    cout<<"14.____________________________________"<<endl;
    cout<<str9+p<<endl;
}


