#include <iostream>
#include<vector>
using std::cout;
using std::endl;


class Stack
{
public:
    Stack(int size):maxSize(size){}

    bool empty(){
        return data.empty();
    }

    bool full()
    {
        return data.size()==maxSize;
    }

    void push(int value)
    {
        if(full())
        {
            cout<<"栈已满，无法添加"<<value<<endl;
        }
        else
        {
            data.push_back(value);
        }
    }

    void pop()
    {
        if(empty())
        {
            cout<<"栈为空，无法出栈"<<endl;
        }
        else
        {
            data.pop_back();
        }
    }

    int top()
    {
        if(empty())
        {
            cout<<"栈为空，没有栈顶元素"<<std::endl;
            return -1;
        }
        else
        {
            return data.back();
        }
    }

private:
    std::vector<int> data;
    int maxSize;

};

int main()
{
    Stack stack(3);

    std::cout << "Testing empty(): " << std::endl;
    std::cout << "Stack is empty: " << stack.empty() << std::endl; // Expected: 1 (true)

    std::cout << "\nTesting push() and top(): " << std::endl;
    stack.push(1);
    std::cout << "Top element after pushing 1: " << stack.top() << std::endl; // Expected: 1

    stack.push(2);
    std::cout << "Top element after pushing 2: " << stack.top() << std::endl; // Expected: 2

    stack.push(3);
    std::cout << "Top element after pushing 3: " << stack.top() << std::endl; // Expected: 3

    stack.push(4); // Should print an error message

    std::cout << "\nTesting full(): " << std::endl;
    std::cout << "Stack is full: " << stack.full() << std::endl; // Expected: 1 (true)

    std::cout << "\nTesting pop() and top(): " << std::endl;
    stack.pop();
    std::cout << "Top element after popping: " << stack.top() << std::endl; // Expected: 2

    stack.pop();
    std::cout << "Top element after popping: " << stack.top() << std::endl; // Expected: 1

    stack.pop();
    stack.pop(); // Should print an error message

    std::cout << "\nTesting empty() again: " << std::endl;
    std::cout << "Stack is empty: " << stack.empty() << std::endl; // Expected: 1 (true)
    
    return 0;
}

