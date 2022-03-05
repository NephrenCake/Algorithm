//Given an integer array nums, return the length of the longest strictly 
//increasing subsequence. 
//
// A subsequence is a sequence that can be derived from an array by deleting 
//some or no elements without changing the order of the remaining elements. For 
//example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7]. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the 
//length is 4.
// 
//
// Example 2: 
//
// 
//Input: nums = [0,1,0,3,2,3]
//Output: 4
// 
//
// Example 3: 
//
// 
//Input: nums = [7,7,7,7,7,7,7]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2500 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time 
//complexity? 
// Related Topics 数组 二分查找 动态规划 👍 2181 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 法二：动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // “状态”定义：（寻找变化信息）memory[i] 的值代表 nums 前 n 个数以 nums[i] 结尾的最长子序列长度。
        // 初始状态：每个元素都至少可以单独成为子序列，所有元素置 1
        vector<int> memory = vector<int>(nums.size(), 1);
        // 边界/轮廓：
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                // 转移方程/决策：
                // 1. 当 nums[i] > nums[j] 时, nums[i] 可以接在 nums[j] 之后，memory[j]++
                // 2. 当 nums[i] <= nums[j] 时： nums[i] 无法接在 nums[j] 之后，跳过。
                if (nums[j] < nums[i])
                    memory[i] = max(memory[i], memory[j] + 1);
        int ans = 1;
        for (int a: memory)
            ans = max(a, ans);
        return ans;
    }
};

// 法一：深搜，记忆化搜索
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        memory = vector<int>(nums.size(), -1);
        int res = 1;
        for (int i = 0; i < nums.size(); ++i)
            res = max(res, dfs(nums, i));
        return res;
    }

    int dfs(vector<int>& nums, int index) {
        if (memory[index] != -1)
            return memory[index];
        memory[index] = 1;
        for (int i = index + 1; i < nums.size(); ++i)
            if (nums[index] < nums[i])
                memory[index] = max(memory[index], dfs(nums, i) + 1);
        return memory[index];
    }

    vector<int> memory;
};

// 尸体2，死因：虽然决策换成从剩余状态选一个，但本质并没有改变时间复杂度，时间爆炸。但是为记忆化做了中间铺垫。
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); ++i)
//             ans = max(ans, dfs(nums, i));
//         return ans;
//     }
//
//     int dfs(vector<int>& nums, int index) {
//         if (index == nums.size())
//             return 0;  // 这是绝对不会进入的
//         int res = 1;
//         for (int i = index + 1; i < nums.size(); ++i)
//             if (nums[i] > nums[index])
//                 res = max(res, dfs(nums, i) + 1);  // 不仅会重复运算，里外res和ans意义相同，但又是不同阶段的结果
//         return res;
//     }
//
//     int ans = 1;
// };

// 尸体1，死因：决策太小，解状态太多，时间爆炸
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         sub.push_back(INT_MIN);
//         dfs(nums, 0);  // 这里可以从0开始，因为决策是选或者不选
//         return ans;
//     }
//
//     void dfs(vector<int>& nums, int index) {
//         if (index == nums.size())
//             return;
//         if (nums[index] > sub[now]) {
//             dfs(nums, index + 1);
//             sub.push_back(nums[index]);
//             now++;
//             ans = max(ans, now);
//             dfs(nums, index + 1);
//             now--;
//             sub.pop_back();
//         } else {
//             dfs(nums, index + 1);
//         }
//     }
//
//     int now = 0;
//     int ans = 0;
//     vector<int> sub;
// };
//leetcode submit region end(Prohibit modification and deletion)
