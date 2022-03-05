//Given two integer arrays preorder and inorder where preorder is the preorder 
//traversal of a binary tree and inorder is the inorder traversal of the same tree,
// construct and return the binary tree. 
//
// 
// Example 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// Example 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder and inorder consist of unique values. 
// Each value of inorder also appears in preorder. 
// preorder is guaranteed to be the preorder traversal of the tree. 
// inorder is guaranteed to be the inorder traversal of the tree. 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1391 👎 0


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
            [3 | 9 | 20,15,7] 告诉我们root=3，不知道左右子树的大小
            [9 | 3 | 15,20,7] 告诉我们左子树1个点，右子树3个点
            in_left  mid       in_right
                [3]
              /    \
            [9]   [20,15,7]
            [9]   [15,20,7]
        */
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    // 通过preorder[pre_left~pre_right]，inorder[in_left~in_right]复原
    TreeNode* build(vector<int>& preorder, int pre_left, int pre_right,
                    vector<int>& inorder, int in_left, int in_right) {
        if (pre_left > pre_right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_left]);
        // 通过找到根在中序（inorder）里面的位置，确定左右子树大小
        int mid = in_left;
        while (inorder[mid] != root->val)
            mid++;
        int leftSize = mid - in_left;  // 左子树大小
        // int rightSize = in_right - mid;  // 右子树大小

        // 递归复原  下标跳过该层根节点
        root->left = build(preorder, pre_left + 1, pre_left + leftSize,
                           inorder, in_left, mid - 1);
        root->right = build(preorder, pre_left + 1 + leftSize, pre_right,
                            inorder, mid + 1, in_right);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
