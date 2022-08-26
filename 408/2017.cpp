#include <bits/stdc++.h>

using namespace std;

//

struct Node {
    char data[10];
    Node *left;
    Node *right;
};

class Solution {
public:
    void dfs(Node *node, int k) {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data;
        } else {
            if (k != 0)
                cout << "(";
            if (node->left != nullptr)
                dfs(node->left, k + 1);
            cout << node->data;
            if (node->right != nullptr)
                dfs(node->right, k + 1);
            if (k != 0)
                cout << ")";
        }
    }

    int expression(Node *root) {
        dfs(root, 0);
    }
};
