//Write an algorithm to find the "next" node (i.e., in-order successor) of a 
//given node in a binary search tree. 
//
// Return null if there's no "next" node for the given node. 
//
// Example 1: 
//
// 
//Input: root = [2,1,3], p = 1
//
//  2
// / \
//1   3
//
//Output: 2 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,null,1], p = 6
//
//      5
//     / \
//    3   6
//   / \
//  2   4
// /   
//1
//
//Output: null 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 86 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return findSucc(root, p->val);
    }

    TreeNode* findSucc(TreeNode* root, int val) {
        TreeNode* ans = nullptr;  // 必须使用空指针初始化，否则结果无厘头
        while (root != nullptr) {  // root会移动
            if (root->val == val) {  // 找到目标，右子树向左走
                if (root->right != nullptr) {
                    ans = root->right;
                    while (ans->left != nullptr) {
                        ans = ans->left;
                    }
                }
                break;
            }
            if (root->val > val) {
                ans = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
