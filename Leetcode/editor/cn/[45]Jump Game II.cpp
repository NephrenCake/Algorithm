//Given an array of non-negative integers nums, you are initially positioned at 
//the first index of the array. 
//
// Each element in the array represents your maximum jump length at that 
//position. 
//
// Your goal is to reach the last index in the minimum number of jumps. 
//
// You can assume that you can always reach the last index. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 
//step from index 0 to 1, then 3 steps to the last index.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,3,0,1,4]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// 0 <= nums[i] <= 1000 
// 
// Related Topics 贪心 数组 动态规划 👍 1385 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int now = 0;
        while (now < nums.size() - 1) {
            // cout << now << endl;
            if (nums[now] == 0)
                return -1;

            int max_next = nums[now] + now;  // 下一步最远到达
            int max_next_next = max_next;  // 下下一步最远到达
            if (max_next >= nums.size() - 1)
                return ans + 1;  // 下一步到达，再继续则越界

            int res = max_next;
            for (int next = now + 1; next <= max_next; ++next)
                if (next + nums[next] >= max_next_next) {
                    max_next_next = next + nums[next];
                    res = next;
                }
            now = res;
            ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
