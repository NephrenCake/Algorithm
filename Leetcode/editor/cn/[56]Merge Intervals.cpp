//Given an array of intervals where intervals[i] = [starti, endi], merge all 
//overlapping intervals, and return an array of the non-overlapping intervals that 
//cover all the intervals in the input. 
//
// 
// Example 1: 
//
// 
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// 
//
// Example 2: 
//
// 
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// 
//
// 
// Constraints: 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
// Related Topics 数组 排序 👍 1284 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 法一：差分
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 注意：不能开差分数组，因为存在[[1,4],[0,0]]，[0,0]也算为一段
        // 由于前闭后闭 [[1,4],[5,6]] -> [[1,4],[5,6]]，所以结束事件不能简单+1

        /*[1, 5]  [2, 6] [3, 4] [6, 10]  [11 12]
           1 2 3 4 5 6 7 8 9 10 11 12
           1 1 1 1 1
             1 1 1 1 1
               1 1
                     1 1 1 1  1
                                  1 1
           +1      -1
             +1      -1
               +1-1
                     +1        -1
                               +1 -1
        把从1覆盖到5这个区间，看作2个事件：
        (a) 在1处，有一个事件：开始覆盖（次数+1）
        (b) 在5处，有一个事件：结束覆盖（次数-1）
        */
        vector<pair<int,int>> events;
        for (vector<int>& interval : intervals) {  // 差分数组
            events.push_back(make_pair(interval[0], 1));
            events.push_back(make_pair(interval[1], -1));
        }
        sort(events.begin(), events.end(),
             [](pair<int,int>& a, pair<int,int>& b) {
                 // 1 在 -1 之前（如果差分是闭区间[1,5]而不是前闭后开[1,6)的话
                 return a.first < b.first || (a.first == b.first && a.second > b.second);
             });
        int count = 0, left;
        vector<vector<int>> ans;
        for (pair<int,int>& event : events) {
            if (count == 0) // 加之前是0，加之后是非0
                left = event.first;  // 一个段的产生
            count += event.second;
            if (count == 0) // 非零变零，一个段的结束
                ans.push_back({left, event.first});
        }
        return ans;
    }
};

// 法二：排序
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 双关键字排序
        // sort(intervals.begin(), intervals.end());  // 直接排序即可
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { // 两个长度为2的数组比较
                 return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
             });  // 排第二个关键字不是必须的

        // 合并
        vector<vector<int>> ans;
        int l = -1, r = -1;
        for (vector<int>& interval: intervals) {
            if (l == -1 && r == -1) {
                l = interval[0];
                r = interval[1];
            }  // 初始化
            if (r >= interval[0]) {
                r = max(interval[1], r);
            } else {
                ans.push_back({l, r});
                l = interval[0];
                r = interval[1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
