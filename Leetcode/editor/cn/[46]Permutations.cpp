//Given an array nums of distinct integers, return all the possible 
//permutations. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
// Related Topics 数组 回溯 👍 1741 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector <vector<int>> ans;
    vector<int> set;
    vector<bool> used;

public:
    vector <vector<int>> permute(vector<int> &nums) {
        used = vector<bool>(nums.size(), false);
        find(nums, 0);
        return ans;
    }

    void find(vector<int>& nums, int count) {
        if (count == nums.size()) {
            ans.push_back(set);
            return;
        }
        for (int i = 0; i < used.size(); ++i) {
            if (!used[i]) {
                set.push_back(nums[i]);
                used[i] = true;
                find(nums, count + 1);
                set.pop_back();
                used[i] = false;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
