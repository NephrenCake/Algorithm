//Given an integer array nums, move all 0's to the end of it while maintaining 
//the relative order of the non-zero elements. 
//
// Note that you must do this in-place without making a copy of the array. 
//
// 
// Example 1: 
// Input: nums = [0,1,0,3,12]
//Output: [1,3,12,0,0]
// Example 2: 
// Input: nums = [0]
//Output: [0]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
//
// 
//Follow up: Could you minimize the total number of operations done? Related 
//Topics 数组 双指针 👍 1392 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j <= nums.size(); ++j) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        for (; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
