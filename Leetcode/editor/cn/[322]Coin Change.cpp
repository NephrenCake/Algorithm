//You are given an integer array coins representing coins of different 
//denominations and an integer amount representing a total amount of money. 
//
// Return the fewest number of coins that you need to make up that amount. If 
//that amount of money cannot be made up by any combination of the coins, return -1.
// 
//
// You may assume that you have an infinite number of each kind of coin. 
//
// 
// Example 1: 
//
// 
//Input: coins = [1,2,5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
// 
//
// Example 2: 
//
// 
//Input: coins = [2], amount = 3
//Output: -1
// 
//
// Example 3: 
//
// 
//Input: coins = [1], amount = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 2³¹ - 1 
// 0 <= amount <= 10⁴ 
// 
// Related Topics 广度优先搜索 数组 动态规划 👍 1683 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 法一：搜索 递归实现 自顶向下
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memory = vector<long long>(amount + 1, -1);
        long long ans = dfs(coins, amount);
        return ans < INT_MAX? ans : -1;
    }

    long long dfs(vector<int>& coins, long long amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;  // 如果有 INT_MAX 则承载的格式用 long long
        if (memory[amount] != -1) return memory[amount];

        memory[amount] = INT_MAX;
        for (int& coin: coins)
            memory[amount] = min(memory[amount], dfs(coins, amount - coin) + 1);
        return memory[amount];
    }

    vector<long long> memory;  // 存的是结果，是需要优化的目标
};

// 法二：动规 递推实现 自底向上
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> need = vector<int>(amount + 1, INT_MAX);
        need[0] = 0;  // 初始化
        for (int i = 1; i <= amount; ++i)  // 递增
            for (int& coin: coins)  // 枚举可能的面值
                if (i - coin >= 0 && need[i - coin] != INT_MAX)  // 确保int不会溢出，或者换成longlong
                    need[i] = min(need[i], need[i - coin] + 1);  // 缺硬币的才需要+1
        return need[amount] == INT_MAX ? -1 : need[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
