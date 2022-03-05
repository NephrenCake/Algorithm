//You are given an array of integers nums, there is a sliding window of size k 
//which is moving from the very left of the array to the very right. You can only 
//see the k numbers in the window. Each time the sliding window moves right by one 
//position. 
//
// Return the max sliding window. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// Example 2: 
//
// 
//Input: nums = [1], k = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 1356 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // 双端队列，存下标（即时间）
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 保证队头合法性，弹出过期队头（最大值）
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            // 维护队列单调递减，新数必须小于队尾
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // 取队头更新答案
            if (i >= k - 1)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
    /*
     * 1 3 [-1 -3 5] 3 6 7
     *
     * 时间：expire_time(-1) < expire_time(-3) < expire_time(5)
     * 值大小：-1 < -3 < 5
     * 求max
     *
     * 冗余：一个下标i一个下标j，如果i<j，并且nums[i]<=nums[j]，i是冗余
     * 去除冗余：维护下标（时间）递增、nums递减（>=）的队列
     * 队头最优，随着下标增长，队头expire后，后面的开始逐渐变成最优
     *
     * */
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue <pair<int, int>> q;  // pair<值，下标>  priority_queue根据first排序
        for (int i = 0; i < k - 1; i++)
            q.push(make_pair(nums[i], i));  // 初始化滑动窗口

        for (int i = k - 1; i < nums.size(); i++) {
            q.push(make_pair(nums[i], i));
            while (q.top().second < i - k + 1)  // 本质是堆顶而不是队头
                q.pop();  // 懒惰删除，检查堆顶下标是否在窗口内，否则持续删除至合法
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
