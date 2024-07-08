#include <iostream>
#include <cstring>
using namespace std;
class String {
public:
    String(const char* pstr);
    ~String();
    char& operator[](size_t idx);
    friend std::ostream& operator<<(std::ostream& os, const String& rhs);

private:
    union Buffer {
        char* _pointer;
        char _local[16];
    };

    size_t _size;
    size_t _capacity;
    Buffer _buffer;
};

String::String(const char*ptr)
:_size(strlen(ptr)),_capacity(_size)
{
    if(_size<=15)
    {
        strcpy(_buffer._local,ptr);
    }
    else
    {
        _buffer._pointer=new char [_size+1];
        strcpy(_buffer._pointer,ptr);
    }
}

String::~String()
{
    if(_size>15)
    {
        delete []_buffer._pointer;
    }
}

char & String::operator[](size_t idx)
{
    return (_size<=15)?_buffer._local[idx]:_buffer._pointer[idx];
}

ostream& operator<<(ostream &os,const String& rhs)
{
    if(rhs._size<=15)
    {
        os<<rhs._buffer._local;
    }
    else
    {
        os<<rhs._buffer._pointer;
    }

    return os;
}

void test0()
{
       String str1("hello");
    String str2("hello, world!!!!!");
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str1[1]: " << str1[1] << std::endl;
    std::cout << "str2[1]: " << str2[1] << std::endl;
    str1[1] = 'a';
    str2[1] = 'a';
    std::cout << "Modified str1: " << str1 << std::endl;
    std::cout << "Modified str2: " << str2 << std::endl;
}

int main()
{
    test0();
    return 0;
}
