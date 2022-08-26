#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *fast = head, *slow = head;
        while (k > 0) {
            if (fast != nullptr) {
                fast = fast->next;
                k--;
            }
        }
        while (fast!= nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
