#include <iostream>
#include<vector>
#include<functional>

using namespace std;

template<typename T,typename Compare=std::less<T>>
class MyQsort
{
public:
    MyQsort(T*arr,size_t size,Compare com=Compare())
    {
        _vec.assign(arr,arr+size);
        quick(0,_vec.size()-1,com);
    }
    
    void quick(int left,int right,Compare &com)
    {
        if(left<right)
        {
            int pivotlndex=partition(left,right,com);
            quick(left,pivotlndex-1,com);
            quick(pivotlndex+1,right,com);
        }
    }

    int partition(int left,int right,Compare &com)
    {
        T pivot=_vec[right];
        int i=left-1;
        for(int j=left;j<right;++j)
        {
            if(com(_vec[j],pivot))
            {
                ++i;
                std::swap(_vec[i],_vec[j]);
            }
        }
        std::swap(_vec[i+1],_vec[right]);
        return i+1;
    }

    void print()
    {
        for(const T&elem:_vec)
        {
            cout<<elem<<" ";
        }
        cout<<endl;
    }

private:
    vector<T>_vec;
};

int main()
{
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // 创建MyQsort对象并进行排序
    MyQsort<int> sorter(arr, size);

    // 打印排序后的数组
    sorter.print();
    return 0;
}

