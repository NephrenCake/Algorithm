//You are a professional robber planning to rob houses along a street. Each 
//house has a certain amount of money stashed, the only constraint stopping you from 
//robbing each of them is that adjacent houses have security systems connected and 
//it will automatically contact the police if two adjacent houses were broken 
//into on the same night. 
//
// Given an integer array nums representing the amount of money of each house, 
//return the maximum amount of money you can rob tonight without alerting the 
//police. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,1]
//Output: 4
//Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//Total amount you can rob = 1 + 3 = 4.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,7,9,3,1]
//Output: 12
//Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 
//(money = 1).
//Total amount you can rob = 2 + 9 + 1 = 12.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 400 
// 
// Related Topics 数组 动态规划 👍 1860 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        // 状态定义：dp[i][j] 代表第 i 天在（j==0 不偷 j==1 偷）的情况下最高能获得多少钱
        vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1, vector<int>(2, INT_MIN));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i < nums.size() + 1; ++i) {
            // 状态转移：
            dp[i][1] = dp[i - 1][0] + nums[i - 1];  // 注意，这里在num[i - 1]表示第i间的财产
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        int ans = 0;
        for (int i = 1; i < nums.size() + 1; ++i)
            for (int j = 0; j < 2; ++j)
                ans = max(ans, dp[i][j]);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
