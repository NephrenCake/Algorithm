#include <bits/stdc++.h>

using namespace std;

// 求带权路径和

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
};

class Solution {
public:
    int dfs(ListNode *node, int k) {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
            return node->val * k;
        return dfs(node->left, k + 1) + dfs(node->right, k + 1);
    }

    int getWPL(ListNode *root) {
        return dfs(root, 0);
    }
};
