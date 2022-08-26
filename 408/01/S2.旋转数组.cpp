#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr)
            return nullptr;
        ListNode *p = head, *q = head;
        int cnt = 0;
        while (q != nullptr)
            q = q->next, cnt++;
        k %= cnt;  // k可能大于链表长度，所有先遍历一遍求长度取余
        q = head;
        while (k != 0)
            q = q->next, k--;  // fast先走k
        while (q->next != nullptr) {  // 用next，实际是走到k-1处，这样可以省一个pre指针，方便删除
            q = q->next;
            p = p->next;
        }  // 一起走
        q->next = head;  // 尾巴要连上头
        head = p->next;  // 换新头
        p->next = nullptr;  // 砍旧尾
        return head;
    }
};
