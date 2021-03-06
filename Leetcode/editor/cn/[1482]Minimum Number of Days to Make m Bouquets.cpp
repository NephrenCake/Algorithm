//You are given an integer array bloomDay, an integer m and an integer k. 
//
// You want to make m bouquets. To make a bouquet, you need to use k adjacent 
//flowers from the garden. 
//
// The garden consists of n flowers, the iᵗʰ flower will bloom in the bloomDay[
//i] and then can be used in exactly one bouquet. 
//
// Return the minimum number of days you need to wait to be able to make m 
//bouquets from the garden. If it is impossible to make m bouquets return -1. 
//
// 
// Example 1: 
//
// 
//Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
//Output: 3
//Explanation: Let us see what happened in the first three days. x means flower 
//bloomed and _ means flower did not bloom in the garden.
//We need 3 bouquets each should contain 1 flower.
//After day 1: [x, _, _, _, _]   // we can only make one bouquet.
//After day 2: [x, _, _, _, x]   // we can only make two bouquets.
//After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// 
//
// Example 2: 
//
// 
//Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
//Output: -1
//Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 
//flowers. We only have 5 flowers so it is impossible to get the needed bouquets and 
//we return -1.
// 
//
// Example 3: 
//
// 
//Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
//Output: 12
//Explanation: We need 2 bouquets each should have 3 flowers.
//Here is the garden after the 7 and 12 days:
//After day 7: [x, x, x, x, _, x, x]
//We can make one bouquet of the first three flowers that bloomed. We cannot 
//make another bouquet from the last three flowers that bloomed because they are not 
//adjacent.
//After day 12: [x, x, x, x, x, x, x]
//It is obvious that we can make two bouquets in different ways.
// 
//
// 
// Constraints: 
//
// 
// bloomDay.length == n 
// 1 <= n <= 10⁵ 
// 1 <= bloomDay[i] <= 10⁹ 
// 1 <= m <= 10⁶ 
// 1 <= k <= n 
// 
// Related Topics 数组 二分查找 👍 232 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 花越开越多，所以解空间必单调
        int MAX = 1000000001;  // 界外
        int l = 0, r = MAX;
        while (l < r) {
            int mid = (l + r) / 2;
            if (isValid(bloomDay, m, k, mid))  // 满足要求，限制T
                r = mid;
            else
                l = mid + 1;
        }
        if (r == MAX)
            return -1;
        return r;
    }

    // T 为天数
    // 制作 m 束花，使用相邻的 k 朵花。
    bool isValid(vector<int>& bloomDay, int m, int k, int T) {
        int group = 0;
        int count = 0;
        for (int& b: bloomDay) {
            if (b <= T) {  // 可以摘
                count++;
                if (count == k) {  // 满一束花了
                    count = 0;
                    group++;
                }
            } else {  // 不可以摘
                count = 0;
            }
        }
        return group >= m;  // 总共的花束能否满足要求
    }
};
//leetcode submit region end(Prohibit modification and deletion)
