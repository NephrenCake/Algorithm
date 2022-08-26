#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

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
    // void print(ListNode *head, string str = " ") {
    //     ListNode *p = head;
    //     cout << str << ": ";
    //     while (p != nullptr) {
    //         cout << p->val << " ";
    //         p = p->next;
    //     }
    //     cout << endl;
    // }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *h = head, *p = l1, *q = l2;
        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                h->next = p;
                p = p->next;
            } else {
                h->next = q;
                q = q->next;
            }
            h = h->next;
        }
        h->next = p != nullptr ? p : q;
        // print(head->next);
        return head->next;
    }
};
