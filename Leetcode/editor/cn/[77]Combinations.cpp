//Given two integers n and k, return all possible combinations of k numbers out 
//of the range [1, n]. 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 4, k = 2
//Output:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 1
//Output: [[1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 数组 回溯 👍 837 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> set;

public:
    vector<vector<int>> combine(int n, int k) {
        findCombine(n, k, 1);
        return ans;
    }

    void findCombine(int n, int k, int l) {
        if (l + k > n + 1 || k == 0) {
            if (k == 0)
                ans.push_back(set);
            return;
        }
        // 包含
        set.push_back(l);
        findCombine(n, k - 1, l + 1);
        // 不包含
        set.pop_back();
        findCombine(n, k, l + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
