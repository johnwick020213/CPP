#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int *p=(int*)malloc(sizeof(int));
    *p=100;
    free(p);

    int *p2=static_cast<int*>(malloc(sizeof(int)));
    *p=100;
    free(p2);

    const char*pstr="hello";

    int *pint=(int*)pstr;

    char *pc=(char*)pstr;
}

int main()
{
    test0();
    return 0;
}

