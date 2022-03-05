//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[
//k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. 
//
// Notice that the solution set must not contain duplicate triplets. 
//
// 
// Example 1: 
// Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
// Example 2: 
// Input: nums = []
//Output: []
// Example 3: 
// Input: nums = [0]
//Output: []
// 
// 
// Constraints: 
//
// 
// 0 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
// Related Topics 数组 双指针 排序 👍 4209 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // nums[i] + nums[j] + nums[k] = 0
        // nums[j] + nums[k] = -nums[i]
        // i < j < k
        vector <vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            auto all_two_sum = twoSum(nums, i + 1, -nums[i]);
            for (auto jk: all_two_sum) {
                ans.push_back({nums[i], jk[0], jk[1]});
            }
        }
        return ans;
    }

private:
    vector <vector<int>> twoSum(vector<int> &numbers, int start, int target) {
        vector <vector<int>> ans;
        int j = numbers.size() - 1;
        for (int i = start; i < j; i++) {
            if (i > start && numbers[i] == numbers[i - 1])
                continue;
            // 以下两处都要判断 i < j 防止 -- 时出界
            while (i < j && numbers[i] + numbers[j] > target)
                j--;
            if (i < j && numbers[i] + numbers[j] == target)
                ans.push_back({numbers[i], numbers[j]});
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
