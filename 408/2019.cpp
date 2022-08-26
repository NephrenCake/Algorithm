#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/reorder-list/

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
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *findMid(ListNode *head) {
        ListNode *l = head, *r = head->next;
        while (r != nullptr && r->next != nullptr) {
            l = l->next;
            r = r->next->next;
        }
        return l;
    }

    ListNode *reverse(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode *p = head, *q = head->next, *r;
        p->next = nullptr;
        while (q != nullptr) {
            if (q->next == nullptr) {
                q->next = p;
                break;
            } else {
                r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
        }
        return q;
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *p = a, *q = b, *m, *n;
        while (p != nullptr && q != nullptr) {
            m = p->next, n = q->next;
            p->next = q, q->next = m;
            p = m, q = n;
        }
        return a;
    }

    // void print(ListNode *head, string str) {
    //     ListNode *p = head;
    //     cout << str << ": ";
    //     while (p != nullptr) {
    //         cout << p->val << " ";
    //         p = p->next;
    //     }
    //     cout << endl;
    // }

    void reorderList(ListNode *head) {
        // print(head, "head");
        ListNode *mid = findMid(head);
        // print(mid, "mid");
        ListNode *last = reverse(mid->next);
        // print(last, "last");
        mid->next = nullptr;
        merge(head, last);
    }
};
