//Given two strings word1 and word2, return the minimum number of operations 
//required to convert word1 to word2. 
//
// You have the following three operations permitted on a word: 
//
// 
// Insert a character 
// Delete a character 
// Replace a character 
// 
//
// 
// Example 1: 
//
// 
//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Explanation: 
//horse -> rorse (replace 'h' with 'r')
//rorse -> rose (remove 'r')
//rose -> ros (remove 'e')
// 
//
// Example 2: 
//
// 
//Input: word1 = "intention", word2 = "execution"
//Output: 5
//Explanation: 
//intention -> inention (remove 't')
//inention -> enention (replace 'i' with 'e')
//enention -> exention (replace 'n' with 'x')
//exention -> exection (replace 'n' with 'c')
//exection -> execution (insert 'u')
// 
//
// 
// Constraints: 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 and word2 consist of lowercase English letters. 
// 
// Related Topics 字符串 动态规划 👍 2078 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = " " + word1;
        word2 = " " + word2;
        // 状态定义：dp[i][j] 表示取 word1 前 i 位和 word2 前 j 位所使用的最少操作数
        vector<vector<int>> dp = vector<vector<int>>(word1.size(), vector<int>(word2.size(), INT_MAX));
        // 初值
        for (int i = 0; i < word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j < word2.size(); ++j)
            dp[0][j] = j;
        // dp
        for (int i = 1; i < word1.size(); ++i)
            for (int j = 1; j < word2.size(); ++j) {  // 注意越界
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word2[j] != word1[i]));  // 注意状态转移表达式是否与写的一样
            }
        return dp[word1.size() - 1][word2.size() - 1];  // 注意越界
    }
};
//leetcode submit region end(Prohibit modification and deletion)
