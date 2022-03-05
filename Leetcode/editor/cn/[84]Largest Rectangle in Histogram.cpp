//Given an array of integers heights representing the histogram's bar height 
//where the width of each bar is 1, return the area of the largest rectangle in the 
//histogram. 
//
// 
// Example 1: 
//
// 
//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1.
//The largest rectangle is shown in the red area, which has an area = 10 units.
// 
//
// Example 2: 
//
// 
//Input: heights = [2,4]
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= heights.length <= 10⁵ 
// 0 <= heights[i] <= 10⁴ 
// 
// Related Topics 栈 数组 单调栈 👍 1704 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0); // 帮助我们在最后把栈清空
        stack <Rect> s;
        int ans = 0;
        // 每个柱子入栈、出栈各一次，2n=O(n)
        // 第一步：for 每个元素
        for (int h : heights) {
            int accumulated_width = 0;
            // 第二步：while (栈顶不满足高度单调性) 累加宽度，出栈
            while (!s.empty() && s.top().height >= h) {
                accumulated_width += s.top().width;
                ans = max(ans, accumulated_width * s.top().height);
                s.pop();
            }
            // 第三步：新元素入栈
            s.push({h, accumulated_width + 1});
        }
        return ans;
    }

private:
    struct Rect {
        int height;
        int width;
    };
};
//leetcode submit region end(Prohibit modification and deletion)
