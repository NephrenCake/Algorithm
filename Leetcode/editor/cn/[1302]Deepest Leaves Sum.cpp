#include <bits/stdc++.h>

using namespace std;

//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, int> dfs(TreeNode *node, int k) {
        if (node == nullptr)
            return {0, -1};
        if (node->left == nullptr && node->right == nullptr)
            return {node->val, k};
        if (node->left == nullptr)
            return dfs(node->right, k + 1);
        if (node->right == nullptr)
            return dfs(node->left, k + 1);

        pair<int, int> r = dfs(node->right, k + 1);
        pair<int, int> l = dfs(node->left, k + 1);
        if (r.second > l.second)
            return r;
        else if (r.second < l.second)
            return l;
        else
            return {r.first + l.first, r.second};
    }

    int deepestLeavesSum(TreeNode *root) {
        return dfs(root, 0).first;
    }
};
