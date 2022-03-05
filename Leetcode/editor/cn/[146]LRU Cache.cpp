//Design a data structure that follows the constraints of a Least Recently Used 
//(LRU) cache. 
//
// Implement the LRUCache class: 
//
// 
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity. 
//
// int get(int key) Return the value of the key if the key exists, otherwise 
//return -1. 
// void put(int key, int value) Update the value of the key if the key exists. 
//Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
//the capacity from this operation, evict the least recently used key. 
// 
//
// The functions get and put must each run in O(1) average time complexity. 
//
// 
// Example 1: 
//
// 
//Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//Explanation
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10⁴ 
// 0 <= value <= 10⁵ 
// At most 2 * 10⁵ calls will be made to get and put. 
// 
// Related Topics 设计 哈希表 链表 双向链表 👍 1865 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Node {
//public:
//    int key;
//    int value;
//    Node *pre;
//    Node *next;
//};

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node *pre;
        Node *next;
    };

    int capacity;
    map<int, Node *> key2node;
    Node *head;
    Node *tail;

    void removeFromList(Node *node) {
        // 让前后节点跳过当前
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void insertToList(Node *node) {
        // 建立与后者的联系
        head->next->pre = node;
        node->next = head->next;
        // 建立与前者的联系
        head->next = node;
        node->pre = head;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (key2node.find(key) == key2node.end())
            return -1;
        Node *res = key2node[key];
        removeFromList(res);
        insertToList(res);
        return res->value;
    }

    void put(int key, int value) {
        if (key2node.find(key) == key2node.end()) {
            Node* node = new Node();
            node->key = key;
            node->value = value;
            insertToList(node);
            key2node[key] = node;
        } else {
            Node* node = key2node[key];
            node->value = value;
            removeFromList(node);
            insertToList(node);
        }
        if (key2node.size() > capacity) {
            Node* node = tail->pre;
            removeFromList(node);
            key2node.erase(node->key);
            delete node;
        }
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
