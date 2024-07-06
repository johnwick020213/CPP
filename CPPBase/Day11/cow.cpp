#include <iostream>
#include <cstring>

class CowString {
private:
    struct StringData {
        char* data;
        int refCount;
        
        StringData(const char* str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
            refCount = 1;
        }

        ~StringData() {
            delete[] data;
        }
    };

    StringData* strData;

public:
    // 内部类，用于处理operator[]返回的对象
    class CharProxy {
    private:
        CowString& cowString;
        size_t index;

    public:
        CharProxy(CowString& cs, size_t i) : cowString(cs), index(i) {}

        // 读操作
        operator char() const {
            return cowString.strData->data[index];
        }

        // 写操作
        CharProxy& operator=(char c) {
            // 如果引用计数大于1，执行写时复制
            if (cowString.strData->refCount > 1) {
                CowString::StringData* newStrData = new CowString::StringData(cowString.strData->data);
                cowString.strData->refCount--;
                cowString.strData = newStrData;
            }
            cowString.strData->data[index] = c;
            return *this;
        }
    };

    CowString(const char* str = "") : strData(new StringData(str)) {}

    CowString(const CowString& other) : strData(other.strData) {
        strData->refCount++;
    }

    ~CowString() {
        if (--strData->refCount == 0) {
            delete strData;
        }
    }

    CowString& operator=(const CowString& other) {
        if (this != &other) {
            if (--strData->refCount == 0) {
                delete strData;
            }
            strData = other.strData;
            strData->refCount++;
        }
        return *this;
    }

    CharProxy operator[](size_t index) {
        return CharProxy(*this, index);
    }

    const char operator[](size_t index) const {
        return strData->data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const CowString& str) {
        os << str.strData->data;
        return os;
    }
};

int main() {
    CowString str1 = "Hello";
    CowString str3 = str1;

    std::cout << str1[0] << std::endl; // 读操作
    str1[0] = 'H';                    // 写操作
    std::cout << str3[0] << std::endl; // 检查str3内容是否被改变

    return 0;
}

