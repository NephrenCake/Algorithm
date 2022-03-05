//Given a non-empty array nums containing only positive integers, find if the 
//array can be partitioned into two subsets such that the sum of elements in both 
//subsets is equal. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,5,11,5]
//Output: true
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,5]
//Output: false
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
// Related Topics 数组 动态规划 👍 1115 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        nums.insert(nums.begin(), 0);  // 1~n
        int sum = 0;
        for (int i = 1; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;  // 奇数不可能分两半
        sum /= 2;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); i++)
            for (int j = sum; j >= nums[i]; j--)
                // 求方法总数用 +，求最优化用 max min，是否可行用 |
                dp[j] = dp[j] | dp[j - nums[i]];
        return dp[sum];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
