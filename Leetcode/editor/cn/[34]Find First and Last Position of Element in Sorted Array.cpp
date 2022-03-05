//Given an array of integers nums sorted in non-decreasing order, find the 
//starting and ending position of a given target value. 
//
// If target is not found in the array, return [-1, -1]. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
// Example 2: 
// Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
// Example 3: 
// Input: nums = [], target = 0
//Output: [-1,-1]
// 
// 
// Constraints: 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// nums is a non-decreasing array. 
// -10⁹ <= target <= 10⁹ 
// 
// Related Topics 数组 二分查找 👍 1424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        ans.push_back(right);

        left = -1, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        ans.push_back(right);

        if (ans[0] > ans[1])
            return {-1, -1};
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
