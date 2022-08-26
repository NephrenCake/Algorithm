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
        // front,rear��Ƕ��׶�β last��ǻ���
        // ͳһʹ�� front = -1, rear = -1 ����ֱ��������ж϶ӿջ��߻��� last=0�����������һ��ķֽ紦
        TreeNode *queue[10000], *p = root;
        int front = -1, rear = -1, last = 0;
        // ά���������
        int bestSum = INT_MIN, bestDepth = -1, sum = 0, depth = 1;
        // ��ʼ������
        queue[++rear] = p;
        while (front != rear) {
            // �ȳ��ӣ������
            p = queue[++front];
            sum += p->val;
            if (p->left != nullptr)
                queue[++rear] = p->left;
            if (p->right != nullptr)
                queue[++rear] = p->right;
            if (front == last) {
                // ˵��һ���Ѿ���������
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