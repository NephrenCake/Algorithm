//You are given an array of k linked-lists lists, each linked-list is sorted in 
//ascending order. 
//
// Merge all the linked-lists into one sorted linked-list and return it. 
//
// 
// Example 1: 
//
// 
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
// 
//
// Example 2: 
//
// 
//Input: lists = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: lists = [[]]
//Output: []
// 
//
// 
// Constraints: 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] is sorted in ascending order. 
// The sum of lists[i].length won't exceed 10^4. 
// 
// Related Topics 链表 分治 堆（优先队列） 归并排序 👍 1714 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    struct Node {
        int key;
        ListNode* listNode;

        Node(int key, ListNode* listNode) : key(key), listNode(listNode) {}

        bool operator<(const Node& rhs) const {
            return key > rhs.key;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <Node> q;
        for (ListNode* listNode: lists) {
            if (listNode != nullptr)
                q.push(Node(listNode->val, listNode));
        }
        ListNode head;
        ListNode* tail = &head;
        while (!q.empty()) {
            // 取出最小元素
            Node node = q.top();
            q.pop();
            // 在答案链表的末尾插入
            tail->next = node.listNode;  // 建立联系
            tail = tail->next;  // 下一个
            // 当最小被取出后，指针向后移动一位，可能需要插入新的元素
            ListNode* p = node.listNode->next;
            if (p != nullptr) {
                q.push(Node(p->val, p));
            }
        }
        return head.next;
    }
};

/*
 * 错误案例：
 * 不能无脑使用指针
 * priority_queue 不能放指针，否则以地址排序，以下为掉坑尸体
 *
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue < Node * > q;
        for (ListNode* listNode: lists) {
            if (listNode != nullptr)
                q.push(new Node(listNode->val, listNode));
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!q.empty()) {
            // 取出最小元素
            Node* node = q.top();
            q.pop();
            // 在答案链表的末尾插入
            tail->next = node->listNode;  // 建立联系
            tail = tail->next;  // 下一个
            // 当最小被取出后，指针向后移动一位，可能需要插入新的元素
            ListNode* p = node->listNode->next;
            if (p != nullptr) {
                q.push(new Node(p->val, p));
            }
        }
        return head->next;
    }
 */
//leetcode submit region end(Prohibit modification and deletion)

