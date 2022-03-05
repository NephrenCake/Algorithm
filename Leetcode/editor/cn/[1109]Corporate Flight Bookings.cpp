//There are n flights that are labeled from 1 to n. 
//
// You are given an array of flight bookings bookings, where bookings[i] = [
//firsti, lasti, seatsi] represents a booking for flights firsti through lasti (
//inclusive) with seatsi seats reserved for each flight in the range. 
//
// Return an array answer of length n, where answer[i] is the total number of 
//seats reserved for flight i. 
//
// 
// Example 1: 
//
// 
//Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
//Output: [10,55,45,25,25]
//Explanation:
//Flight labels:        1   2   3   4   5
//Booking 1 reserved:  10  10
//Booking 2 reserved:      20  20
//Booking 3 reserved:      25  25  25  25
//Total seats:         10  55  45  25  25
//Hence, answer = [10,55,45,25,25]
// 
//
// Example 2: 
//
// 
//Input: bookings = [[1,2,10],[2,2,15]], n = 2
//Output: [10,25]
//Explanation:
//Flight labels:        1   2
//Booking 1 reserved:  10  10
//Booking 2 reserved:      15
//Total seats:         10  25
//Hence, answer = [10,25]
//
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2 * 10⁴ 
// 1 <= bookings.length <= 2 * 10⁴ 
// bookings[i].length == 3 
// 1 <= firsti <= lasti <= n 
// 1 <= seatsi <= 10⁴ 
// 
// Related Topics 数组 前缀和 👍 300 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> delta(n + 2, 0); // 差分要开0~n+1
        for (auto& booking : bookings) {
            int fir = booking[0];
            int last = booking[1];
            int seats = booking[2];
            // 差分模板
            delta[fir] += seats;
            delta[last + 1] -= seats;
        }

        vector<int> sum(n + 1, 0); // 0~n
        // 1~n  构造前缀和
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + delta[i];

        // 0~n-1  向前移位，去除0
        for (int i = 1; i <= n; i++) sum[i - 1] = sum[i];
        sum.pop_back();
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
