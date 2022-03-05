//Given the head of a linked list, reverse the nodes of the list k at a time, 
//and return the modified list. 
//
// k is a positive integer and is less than or equal to the length of the 
//linked list. If the number of nodes is not a multiple of k then left-out nodes, in 
//the end, should remain as it is. 
//
// You may not alter the values in the list's nodes, only nodes themselves may 
//be changed. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2,3,4,5], k = 3
//Output: [3,2,1,4,5]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is n. 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
// Follow-up: Can you solve the problem in O(1) extra memory space? 
// Related Topics 递归 链表 👍 1436 👎 0


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
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *protect = new ListNode(0, head);
        // 分组
        ListNode *last = protect;
        while (head != nullptr) {
            ListNode *end = getEnd(head, k);
            if (end == nullptr) break;

            ListNode *nextGroupHead = end->next;
            // 处理每组内部的反转
            reverseList(head, end);
            // 上组新结尾连本组新头/旧尾
            last->next = end;
            // 本组新结尾连下组旧头
            head->next = nextGroupHead;

            // 维护
            last = head;
            head = nextGroupHead;
        }
        return protect->next;
    }

    ListNode *getEnd(ListNode *head, int k) {
        k = k - 1;  // k个一组 向后移动k-1次
        while(head != nullptr && k > 0) {
            head = head->next;
            k--;
        }
        return head;
    }

    void reverseList(ListNode *head, ListNode *end) {
        if (head == end) return;  // 可以直接加上特殊情况保证
        // 注意是反转head到end之间
        // head本身不需要指向空
        ListNode *last = head;
        head = head->next;
        while (head != end) {
            // 保留下一个节点的地址
            ListNode *nextHead = head->next;
            // 反转更新当前节点的next为last
            head->next = last;
            // last head 向后移
            last = head;
            head = nextHead;
        }
        head->next = last;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
