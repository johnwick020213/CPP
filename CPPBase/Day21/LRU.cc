#include <iostream>
#include<unordered_map>
#include<memory>
using namespace::std;

//构建双向链表
struct Node
{
    int key,val;
    weak_ptr<Node>prev;
    shared_ptr<Node>next;
    Node():key(0),val(0),prev(),next(nullptr){}
    Node(int _key,int _val):key(_key),val(_val),prev(),next(nullptr){}
};

class LRUCache
{
public:
    //构造函数，初始化双向链表
    LRUCache(int _capacity):capacity(_capacity),size(0)
    {
          head=make_shared<Node>();
          tail=make_shared<Node>();
          head->next=tail;
          tail->prev=head;
    }

    int get(int key)
    {
        if(!h.count(key))return -1;
        auto node=h[key];
        removeNode(node);//删除节点
        addNodeToHead(node);//头部添加
        return node->val;
    }

    void put(int key,int value)
    {
        //哈希表中存在
        if(h.count(key))
        {
            auto node=h[key];
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
                auto rm=tail->prev.lock();
                h.erase(rm->key);
                removeNode(rm);
                size--;
            }
            auto node=make_shared< Node>(key,value);
            addNodeToHead(node);
            h[key]=node;
            size++;
        }
    }

    void removeNode(shared_ptr<Node>node)
    {
        auto prevNode=node->prev.lock();
        prevNode->next=node->next;
        node->next->prev=prevNode;
    }

    void addNodeToHead(shared_ptr<Node>node)
    {
        node->prev=head;
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
    }
private:
    shared_ptr<Node>head,tail;
    unordered_map<int,shared_ptr<Node>> h;
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

