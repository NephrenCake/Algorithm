//Given the head of a singly linked list, reverse the list, and return the 
//reversed list. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2]
//Output: [2,1]
// 
//
// Example 3: 
//
// 
//Input: head = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is the range [0, 5000]. 
// -5000 <= Node.val <= 5000 
// 
//
// 
// Follow up: A linked list can be reversed either iteratively or recursively. 
//Could you implement both? 
// Related Topics éå½ é¾è¡¨ ð 2204 ð 0


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
    ListNode *reverseList(ListNode *head) {
        ListNode *last;
        last = nullptr;
        while (head != nullptr) {
            // ä¿çä¸ä¸ä¸ªèç¹çå°å
            ListNode *nextNode = head->next;
            // åè½¬æ´æ°å½åèç¹çnextä¸ºlast
            head->next = last;
            // last head ååç§»
            last = head;
            head = nextNode;
        }
        return last;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
