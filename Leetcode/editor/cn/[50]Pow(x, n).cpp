//Implement pow(x, n), which calculates x raised to the power n (i.e., xⁿ). 
//
// 
// Example 1: 
//
// 
//Input: x = 2.00000, n = 10
//Output: 1024.00000
// 
//
// Example 2: 
//
// 
//Input: x = 2.10000, n = 3
//Output: 9.26100
// 
//
// Example 3: 
//
// 
//Input: x = 2.00000, n = -2
//Output: 0.25000
//Explanation: 2⁻² = 1/2² = 1/4 = 0.25
// 
//
// 
// Constraints: 
//
// 
// -100.0 < x < 100.0 
// -2³¹ <= n <= 2³¹-1 
// -10⁴ <= xⁿ <= 10⁴ 
// 
// Related Topics 递归 数学 👍 850 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // 扩充范围，防止int数值不对称越界
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);  // 处理负数
    }

    double quickMul(double x, long long n) {
        // 边界
        if (n == 0)
            return 1.0;
        // 分解
        double temp = quickMul(x, n / 2);
        // 合并
        if (n % 2)
            return temp * temp * x;
        else
            return temp * temp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
