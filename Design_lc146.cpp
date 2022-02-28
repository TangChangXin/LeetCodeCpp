//
// Created by XK on 2022/2/23.
//
#include <unordered_map>

using namespace std;

struct s双向链表 {
    int j键, z值;
    s双向链表 *q前驱节点, *h后继节点;
    s双向链表() : j键(0), z值(0), q前驱节点(nullptr), h后继节点(nullptr) {}
    s双向链表(int j键, int z值) : j键(j键), z值(z值), q前驱节点(nullptr), h后继节点(nullptr) {}
};

class LRUCache {
private:
    int r容量;
    s双向链表 *x虚拟头节点, *x虚拟尾结点;
    unordered_map<int, s双向链表 *> h缓存;
public:
    //看了题解。
    //初始化，创建虚拟的头节点和尾结点，不算真正的容量
    LRUCache(int capacity) : r容量(capacity){
        x虚拟头节点 = new s双向链表();
        x虚拟尾结点 = new s双向链表();
        x虚拟头节点->h后继节点 = x虚拟尾结点;
        x虚拟尾结点->q前驱节点 = x虚拟头节点;
    }

    int get(int key) {
        if (!h缓存.count(key))
            return -1; //不存在直接返回-1
        s双向链表 *b被访问节点 = h缓存[key];
        s删除节点(b被访问节点);
        t添加到头部(b被访问节点);
        return b被访问节点->z值;
    }

    void put(int key, int value) {
        if (!h缓存.count(key)) {
            //如果不存在
            s双向链表 *j节点 = new s双向链表(key, value);
            t添加到头部(j节点);
            h缓存[key] = j节点; //添加哈希表中对节点的映射
            if (h缓存.size() > r容量) {
                s双向链表 *z最久未使用节点 = x虚拟尾结点->q前驱节点;
                s删除节点(z最久未使用节点);
                h缓存.erase(z最久未使用节点->j键);
            }
        } else {
            s双向链表 *b被访问节点 = h缓存[key];
            b被访问节点->z值 = value;
            s删除节点(b被访问节点);
            t添加到头部(b被访问节点);
        }
    }

    //添加新元素到缓存的头部
    void t添加到头部(s双向链表 *j节点) {
        j节点->q前驱节点 = x虚拟头节点;
        j节点->h后继节点 = x虚拟头节点->h后继节点;
        x虚拟头节点->h后继节点->q前驱节点 = j节点;
        x虚拟头节点->h后继节点 = j节点;
    }

    //删除节点
    void s删除节点(s双向链表 *j节点) {
        j节点->q前驱节点->h后继节点 = j节点->h后继节点;
        j节点->h后继节点->q前驱节点 = j节点->q前驱节点;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */