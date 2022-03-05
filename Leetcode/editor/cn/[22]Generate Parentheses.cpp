//Given n pairs of parentheses, write a function to generate all combinations 
//of well-formed parentheses. 
//
// 
// Example 1: 
// Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2: 
// Input: n = 1
//Output: ["()"]
// 
// 
// Constraints: 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 动态规划 回溯 👍 2323 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // 记忆化，输入映射到输出，避免计算重复的generateParenthesis(n)
    map<int, vector<string>> h;

public:
    vector<string> generateParenthesis(int n) {
        // 计数（统计）类的分治问题
        //      划分子问题标准：第一个子问题，作为不可分割的整体
        // 分段方法：(a)b
        //      (a)：k+1对括号  a：k对括号
        //      b：n-k-1对括号
        if (n == 0)
            return {""};
        if (h.find(n) != h.end())
            return h[n];

        vector<string> ans;
        for (int k = 0; k < n; ++k) {  // 不同k之间，加法原理
            vector<string> as = generateParenthesis(k);
            vector<string> bs = generateParenthesis(n - 1 - k);
            // ab之间乘法原理
            for (string& a:as)
                for (string& b:bs)
                    ans.push_back("(" + a + ")" + b);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
