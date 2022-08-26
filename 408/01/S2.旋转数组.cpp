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
        k %= cnt;  // k���ܴ��������ȣ������ȱ���һ���󳤶�ȡ��
        q = head;
        while (k != 0)
            q = q->next, k--;  // fast����k
        while (q->next != nullptr) {  // ��next��ʵ�����ߵ�k-1������������ʡһ��preָ�룬����ɾ��
            q = q->next;
            p = p->next;
        }  // һ����
        q->next = head;  // β��Ҫ����ͷ
        head = p->next;  // ����ͷ
        p->next = nullptr;  // ����β
        return head;
    }
};
