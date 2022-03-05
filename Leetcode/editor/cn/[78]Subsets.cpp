//Given an integer array nums of unique elements, return all possible subsets (
//the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in 
//any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// Example 2: 
//
// 
//Input: nums = [0]
//Output: [[],[0]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// All the numbers of nums are unique. 
// 
// Related Topics 位运算 数组 回溯 👍 1455 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> set;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        findSubsets(nums, 0);
        return ans;
    }

    void findSubsets(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(set);
            return;
        }
        // 包括
        set.push_back(nums[index]);
        findSubsets(nums, index + 1);
        // 不包括
        set.pop_back();
        findSubsets(nums, index + 1);

        // 往回走之前，要确保把所有修改的全局变量还原
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
