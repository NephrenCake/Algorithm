#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode *p = headA, *q = headB;
        while (p != nullptr) {
            p = p->next;
            m++;
        }
        while (q != nullptr) {
            q = q->next;
            n++;
        }
        p = headA, q = headB;
        while (m > n) {
            p = p->next;
            m--;
        }
        while (m < n) {
            q = q->next;
            n--;
        }
        while (p != nullptr) {
            if (p == q)
                return p;
            else {
                p = p->next;
                q = q->next;
            }
        }
        return nullptr;
    }
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> set;
//         ListNode *p = headA;
//         while (p != nullptr) {
//             set.insert(p);
//             p = p->next;
//         }
//         p = headB;
//         while (p != nullptr) {
//             if (set.find(p) != set.end())
//                 return p;
//             p = p->next;
//         }
//         return nullptr;
//     }
// };
