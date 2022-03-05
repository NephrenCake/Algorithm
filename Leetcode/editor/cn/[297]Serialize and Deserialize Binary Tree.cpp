//Serialization is the process of converting a data structure or object into a 
//sequence of bits so that it can be stored in a file or memory buffer, or 
//transmitted across a network connection link to be reconstructed later in the same or 
//another computer environment. 
//
// Design an algorithm to serialize and deserialize a binary tree. There is no 
//restriction on how your serialization/deserialization algorithm should work. You 
//just need to ensure that a binary tree can be serialized to a string and this 
//string can be deserialized to the original tree structure. 
//
// Clarification: The input/output format is the same as how LeetCode 
//serializes a binary tree. You do not necessarily need to follow this format, so please be 
//creative and come up with different approaches yourself. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,2,3,null,null,4,5]
//Output: [1,2,3,null,null,4,5]
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 10⁴]. 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 👍 740 👎 0


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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "X,";
        string leftNode = serialize(root->left);
        string rightNode = serialize(root->right);
        return to_string(root->val) + "," + leftNode + rightNode;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        list <string> list = split(data, ',');
        TreeNode *res = buildTree(list);
        return res;
    }

    TreeNode *buildTree(list <string> &strList) {
        string strtmp = strList.front();
        strList.pop_front();
        if (strtmp == "X")
            return nullptr;
        TreeNode *node = new TreeNode(stoi(strtmp));  // str -> int
        node->left = buildTree(strList);
        node->right = buildTree(strList);
        return node;
    }

    list <string> split(string &str, char c) {
        list <string> res;
        for (int lastpos = -1, pos = 0; pos < str.length(); pos++)
            if (str[pos] == c) {
                res.push_back(str.substr(++lastpos, pos - lastpos));
                lastpos = pos;
            }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
