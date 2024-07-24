#include <iostream>
#include<vector>
#include<functional>

using std::cout;
using std::endl;
using std::vector;
template <typename T, typename Compare = std::less<T>> 
class HeapSort 
{ 
public:  
    HeapSort(T *arr, size_t size)
    :_vec(arr,arr+size)
     ,_cmp(Compare())
    {
    }
    
    //堆调整
    void heapAdjust(size_t  start, size_t end)
    {
        size_t parent=start;
        size_t child=2*parent+1;
        T temp=_vec[parent];

        while(child<end)
        {
            //选择较大的节点
            if(child+1<end&&_cmp(_vec[child],_vec[child+1]))
            {
                child++;
            }
            //如果父节点已经大于等于子节点，则跳出循环
            if(!_cmp(temp,_vec[child]))
            {
                break;
            }
            //将子节点赋值给父节点
            _vec[parent]=_vec[child];
            parent=child;
            child=2*parent+1;
        }
        //将父节点值赋值给最终位置
        _vec[parent]=temp;
    }
    void sort()
    {
       //建堆
       for(size_t i=_vec.size()/2;i>0;i--)
       {
           heapAdjust(i-1,_vec.size());
       }
       //排序
       for(size_t i=_vec.size()-1;i>0;i--)
       {
           std::swap(_vec[0],_vec[i]);
           heapAdjust(0,i);
       }
    }

    void print()
    {
        for(const auto &val:_vec)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
private:  
    vector<T> _vec;
    Compare _cmp;
};



int main()
{
    int arr[] = {3, 5, 1, 2, 4, 8, 7, 6};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    HeapSort<int> heapSort(arr, size);
    heapSort.sort();
    heapSort.print();

    
    return 0;
}

