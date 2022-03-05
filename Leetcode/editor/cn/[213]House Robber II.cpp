//You are a professional robber planning to rob houses along a street. Each 
//house has a certain amount of money stashed. All houses at this place are arranged 
//in a circle. That means the first house is the neighbor of the last one. 
//Meanwhile, adjacent houses have a security system connected, and it will automatically 
//contact the police if two adjacent houses were broken into on the same night. 
//
// Given an integer array nums representing the amount of money of each house, 
//return the maximum amount of money you can rob tonight without alerting the 
//police. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,2]
//Output: 3
//Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 
//2), because they are adjacent houses.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,1]
//Output: 4
//Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//Total amount you can rob = 1 + 3 = 4.
// 
//
// Example 3: 
//
// 
//Input: nums = [1,2,3]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 1000 
// 
// Related Topics 数组 动态规划 👍 910 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        // 状态定义：dp[i][j] 代表第 i 天在（j==0 不偷 j==1 偷）的情况下最高能获得多少钱
        // 第一次dp：可以偷 1，则代表了不能偷 n，优化结果为 dp[n, 0]
        vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1, vector<int>(2, INT_MIN));
        dp[1][0] = 0, dp[1][1] = nums[0];
        for (int i = 2; i < nums.size() + 1; ++i) {
            // 状态转移：
            dp[i][1] = dp[i - 1][0] + nums[i - 1];  // 注意，这里在num[i - 1]表示第i间的财产
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        int ans = dp[nums.size()][0];

        // 第二次dp：不可以偷 1，则代表可以偷 n，优化结果为 max(dp[n, 0], dp[n, 1])
        dp[1][0] = dp[1][1] = 0;
        for (int i = 2; i < nums.size() + 1; ++i) {
            // 状态转移：
            dp[i][1] = dp[i - 1][0] + nums[i - 1];  // 注意，这里在num[i - 1]表示第i间的财产
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        ans = max(ans,
                  max(dp[nums.size()][0],
                      dp[nums.size()][1]));
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
