//Given a 1-indexed array of integers numbers that is already sorted in non-
//decreasing order, find two numbers such that they add up to a specific target 
//number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1
// < index2 <= numbers.length. 
//
// Return the indices of the two numbers, index1 and index2, added by one as an 
//integer array [index1, index2] of length 2. 
//
// The tests are generated such that there is exactly one solution. You may not 
//use the same element twice. 
//
// 
// Example 1: 
//
// 
//Input: numbers = [2,7,11,15], target = 9
//Output: [1,2]
//Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We 
//return [1, 2].
// 
//
// Example 2: 
//
// 
//Input: numbers = [2,3,4], target = 6
//Output: [1,3]
//Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We 
//return [1, 3].
// 
//
// Example 3: 
//
// 
//Input: numbers = [-1,0], target = -1
//Output: [1,2]
//Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We 
//return [1, 2].
// 
//
// 
// Constraints: 
//
// 
// 2 <= numbers.length <= 3 * 10⁴ 
// -1000 <= numbers[i] <= 1000 
// numbers is sorted in non-decreasing order. 
// -1000 <= target <= 1000 
// The tests are generated such that there is exactly one solution. 
// 
// Related Topics 数组 双指针 二分查找 👍 667 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 双指针扫描，i从前往后，j从后往前，相遇时停止
        // 时间复杂度为 O(1)
        int j = numbers.size() - 1;
        for (int i = 0; i < j; i++) {
            // 注意是 非递减 且 有唯一答案
            // 注意是两数之和，而不是区间积分
            // 只要是两指针之和比目标大，那问题一定是j太后
            // 只要是两指针之和比目标小，那问题一定是i太前
            while (numbers[i] + numbers[j] > target)
                j--;
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
