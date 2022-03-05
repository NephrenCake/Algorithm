//Given an integer array nums, find the contiguous subarray (containing at 
//least one number) which has the largest sum and return its sum. 
//
// A subarray is a contiguous part of an array. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [1]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: nums = [5,4,-1,7,8]
//Output: 23
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
// Follow up: If you have figured out the O(n) solution, try coding another 
//solution using the divide and conquer approach, which is more subtle. 
// Related Topics 数组 分治 动态规划 👍 4244 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(nums.size());
        dp[0] = nums[0];  // 实际上 dp 只用到动态地最后一个值，且数组前部分的值不再遍历，由result维护，因此dp可以替换成int来维护
        result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
