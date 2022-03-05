//Given a root node reference of a BST and a key, delete the node with the 
//given key in the BST. Return the root node reference (possibly updated) of the BST. 
//
// Basically, the deletion can be divided into two stages: 
//
// 
// Search for a node to remove. 
// If the node is found, delete the node. 
// 
//
// 
// Example 1: 
//
// 
//Input: root = [5,3,6,2,4,null,7], key = 3
//Output: [5,4,6,2,null,null,7]
//Explanation: Given key to delete is 3. So we find the node with value 3 and 
//delete it.
//One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
//Please notice that another valid answer is [5,2,6,null,4,null,7] and it's 
//also accepted.
//
// 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,7], key = 0
//Output: [5,3,6,2,4,null,7]
//Explanation: The tree does not contain a node with value = 0.
// 
//
// Example 3: 
//
// 
//Input: root = [], key = 0
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 10⁴]. 
// -10⁵ <= Node.val <= 10⁵ 
// Each node has a unique value. 
// root is a valid binary search tree. 
// -10⁵ <= key <= 10⁵ 
// 
//
// 
// Follow up: Could you solve it with time complexity O(height of tree)? 
// Related Topics 树 二叉搜索树 二叉树 👍 627 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            // 必须判
            if (root->right == nullptr) {
                return root->left;
            } else if (root->left == nullptr) {
                return root->right;
            } else {  // 这里要找后继
                TreeNode* p = root->right;
                while (p->left != nullptr)
                    p = p->left;
                // 找到后继，后继的值给root，删后继
                root->val = p->val;
                root->right = deleteNode(root->right, p->val);
                return root;
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
