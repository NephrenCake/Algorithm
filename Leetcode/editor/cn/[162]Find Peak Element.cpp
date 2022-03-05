//A peak element is an element that is strictly greater than its neighbors. 
//
// Given an integer array nums, find a peak element, and return its index. If 
//the array contains multiple peaks, return the index to any of the peaks. 
//
// You may imagine that nums[-1] = nums[n] = -∞. 
//
// You must write an algorithm that runs in O(log n) time. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,1]
//Output: 2
//Explanation: 3 is a peak element and your function should return the index 
//number 2. 
//
// Example 2: 
//
// 
//Input: nums = [1,2,1,3,5,6,4]
//Output: 5
//Explanation: Your function can return either index number 1 where the peak 
//element is 2, or index number 5 where the peak element is 6. 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 1000 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// nums[i] != nums[i + 1] for all valid i. 
// 
// Related Topics 数组 二分查找 👍 692 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int lm = (l + r) / 2;  // 不能+1
            int rm = lm + 1;
            if (nums[lm] < nums[rm])  // 三分中不能存在==，必单增单减
                l = rm;  // 丢弃两个左半段
            else
                r = lm;  // 丢弃两个右半段
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
