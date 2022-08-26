#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool cnt[nums.size() + 2];
        for (int i = 1; i < nums.size() + 2; i++)
            cnt[i] = false;  // 一定要赋初值
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0 && nums[i] <= nums.size())  // 防止越界
                cnt[nums[i]] = true;
        for (int i = 1; i < nums.size() + 2; i++)
            if (!cnt[i])
                return i;
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums({7,8,9,11,12});
    cout << s.firstMissingPositive(nums);
}
