//Given an integer array nums, find a contiguous non-empty subarray within the 
//array that has the largest product, and return the product. 
//
// The test cases are generated so that the answer will fit in a 32-bit integer.
// 
//
// A subarray is a contiguous subsequence of the array. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -10 <= nums[i] <= 10 
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit 
//integer. 
// 
// Related Topics 数组 动态规划 👍 1469 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 状态定义：min_arr[i] 表示以 i 为结尾的乘积最小子数组；max_arr[i] 表示以 i 为结尾的乘积最大子数组
        vector<int> min_arr = vector<int>(nums.size(), 1);
        vector<int> max_arr = vector<int>(nums.size(), 1);
        int ans = min_arr[0] = max_arr[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            max_arr[i] = max(nums[i],
                             max(nums[i] * min_arr[i - 1],
                                 nums[i] * max_arr[i - 1]));
            min_arr[i] = min(nums[i],
                             min(nums[i] * min_arr[i - 1],
                                 nums[i] * max_arr[i - 1]));
            ans = max(ans, max_arr[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
