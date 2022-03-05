//Given a non-negative integer x, compute and return the square root of x. 
//
// Since the return type is an integer, the decimal digits are truncated, and 
//only the integer part of the result is returned. 
//
// Note: You are not allowed to use any built-in exponent function or operator, 
//such as pow(x, 0.5) or x ** 0.5. 
//
// 
// Example 1: 
//
// 
//Input: x = 4
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: x = 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since the decimal part 
//is truncated, 2 is returned. 
//
// 
// Constraints: 
//
// 
// 0 <= x <= 2³¹ - 1 
// 
// Related Topics 数学 二分查找 👍 875 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        // int要爆，用long防止溢出
        // right直接x，而不是x-1
        long long left = 0, right = x;
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (mid * mid <= x)
                left = mid;  // 看到left=mid往右走，则上面+1
            else
                right = mid - 1;
        }
        return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
