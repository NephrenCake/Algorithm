//Given an array nums which consists of non-negative integers and an integer m, 
//you can split the array into m non-empty continuous subarrays. 
//
// Write an algorithm to minimize the largest sum among these m subarrays. 
//
// 
// Example 1: 
//
// 
//Input: nums = [7,2,5,10,8], m = 2
//Output: 18
//Explanation:
//There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8],
//where the largest sum among the two subarrays is only 18.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,4,5], m = 2
//Output: 9
// 
//
// Example 3: 
//
// 
//Input: nums = [1,4,4], m = 3
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 10⁶ 
// 1 <= m <= min(50, nums.length) 
// 
// Related Topics 贪心 数组 二分查找 动态规划 👍 610 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // m组之内，每组T以内
    int splitArray(vector<int>& nums, int m) {
        // 初始化 l r
        int l = 0, r = 0;
        for (int& n: nums) {
            l = max(l, n);
            r += n;
        }
        // 二分答案
        while (l < r) {
            int mid = (l + r) / 2;
            if (isValid(nums, m, mid))  // 可行则限制T大小
                r = mid;
            else  // 放松T的限制
                l = mid + 1;
        }
        // 最终 r 就是解空间中的最小值 18
        return r;
    }

    bool isValid(vector<int>& nums, int m, int T) {
        int group = 1;
        int sum = 0;
        for (int& n: nums) {
            if (sum + n <= T) {
                sum += n;  // 在不超出容量时放入
            } else {
                group++;  // 新开一组
                sum = n;
            }
        }
        return group <= m;  // 小于等于m组才可行
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/*
 * 要理解解空间的意义，最大的最小值和最小的最大值，是否包含
class Solution {
public:
    // m组之内，每组T以内
    int splitArray(vector<int>& nums, int m) {
        // 初始化 l r
        int l = 0, r = 0;
        for (int& n: nums) {
            l = max(l, n);
            r += n;
        }
        // 二分答案
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (isValid(nums, m, mid))  // m要求不能满足，需要放松T的限制
                l = mid;
            else  // 限制T
                r = mid - 1;
        }
        // 最终 r 就是非解空间中的最大值 17
        return r + 1;
    }

    bool isValid(vector<int>& nums, int m, int T) {
        int group = 1;
        int sum = 0;
        for (int& n: nums) {
            if (sum + n <= T) {
                sum += n;  // 在不超出容量时放入
            } else {
                group++;  // 新开一组
                sum = n;
            }
        }
        return group > m;  // 大于m组时，需要放松T的限制
    }
};
 */
