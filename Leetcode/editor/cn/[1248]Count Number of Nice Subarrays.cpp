//Given an array of integers nums and an integer k. A continuous subarray is 
//called nice if there are k odd numbers on it. 
//
// Return the number of nice sub-arrays. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,2,1,1], k = 3
//Output: 2
//Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1
//].
// 
//
// Example 2: 
//
// 
//Input: nums = [2,4,6], k = 1
//Output: 0
//Explanation: There is no odd numbers in the array.
// 
//
// Example 3: 
//
// 
//Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//Output: 16
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 50000 
// 1 <= nums[i] <= 10^5 
// 1 <= k <= nums.length 
// Related Topics 数组 哈希表 数学 滑动窗口 👍 201 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        /*
         *  暴力：
         *  for r = 1 ~ n
         *      for l = 1 ~ r
         *          if s[r] - s[l - 1] == k:
         *              ans += 1
         *
         *  优化：
         *  对于每个 r(1~n) 有几个 l(1~r) 使得 s[r]-s[l-1]=k
         *  对于每个 r(1~n) 有几个 l(1~r) 使得 s[r]-k=s[l-1]
         *  for r = 1 ~ n
         *      return count[s[r]-k]
         *
         *  在此之前就要构造 count[] 用于统计 s[l-1] （也正因为索引 l-1 所以要在前面插零，代表的意义是空集）
         *
         */

        // 开头插入一个0，转化成下标1~n
        nums.insert(nums.begin(), 0);
        // 前缀和，下标0~n
        vector<int> sum(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {  // 开头插一个0，可以防止这里越界，同时从1开始
            sum[i] = sum[i - 1] + nums[i] % 2;
        }
        // 计数，下标0~n
        vector<int> count(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            count[sum[i]]++;  // 下标0也就是表示包含了字数组为空的情况
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 判断是为了防止数组越界；若使用 map 则判断是否存在，存在则加
            ans += sum[i] - k >= 0 ? count[sum[i] - k] : 0;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
