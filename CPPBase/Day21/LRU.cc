#include <iostream>
#include<unordered_map>

using namespace::std;

//构建双向链表
struct Node
{
    int key,val;
    Node* prev,*next;
    Node():key(0),val(0),prev(nullptr),next(nullptr){}
    Node(int _key,int _val):key(_key),val(_val),prev(nullptr),next(nullptr){}
};

class LRUCache
{
public:
    //构造函数，初始化双向链表
    LRUCache(int _capacity):capacity(_capacity),size(0)
    {
          head=new Node();
          tail=new Node();
          head->next=tail;
          tail->prev=head;
    }

    int get(int key)
    {
        if(!h.count(key))return -1;
        Node*node=h[key];
        removeNode(node);//删除节点
        addNodeToHead(node);//头部添加
        return node->val;
    }

    void put(int key,int value)
    {
        //哈希表中存在
        if(h.count(key))
        {
            Node*node=h[key];
            node->val=value;
            removeNode(node);
            addNodeToHead(node);
        }
        //哈希表中不存在
        else
        {
            //容量已满，尾部删除
            if(size==capacity)
            {
                Node *rm=tail->prev;
                h.erase(rm->key);
                removeNode(rm);
                size--;
            }
            Node*node=new Node(key,value);
            addNodeToHead(node);
            h[key]=node;
            size++;
        }
    }

    void removeNode(Node *node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void addNodeToHead(Node*node)
    {
        node->prev=head;
        node->next=head->next;
        head->next=node;
    }
private:
    Node*head,*tail;
    unordered_map<int,Node*> h;
    int capacity,size;
};

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1); // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2); // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1); // 返回 -1 (未找到)
    lRUCache.get(3); // 返回 3
    lRUCache.get(4); // 返回 4
    return 0;
}

