#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/submissions/

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
    int maxLevelSum(TreeNode *root) {
        // front,rear标记队首队尾 last标记换层
        // 统一使用 front = -1, rear = -1 可以直接用相等判断队空或者换层 last=0即放入根结点第一层的分界处
        TreeNode *queue[10000], *p = root;
        int front = -1, rear = -1, last = 0;
        // 维护特殊变量
        int bestSum = INT_MIN, bestDepth = -1, sum = 0, depth = 1;
        // 初始化队列
        queue[++rear] = p;
        while (front != rear) {
            // 先出队，再入队
            p = queue[++front];
            sum += p->val;
            if (p->left != nullptr)
                queue[++rear] = p->left;
            if (p->right != nullptr)
                queue[++rear] = p->right;
            if (front == last) {
                // 说明一层已经遍历完了
                if (bestSum < sum) {
                    bestSum = sum;
                    bestDepth = depth;
                }
                sum = 0;
                depth++;
                last = rear;
            }
        }
        return bestDepth;
    }
};