#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/rotate-array/

class Solution {
public:
    void reverse(vector<int> &nums, int s, int e) {
        for (int i = 0; i < (e - s + 1) / 2; i++) {
            int t = nums[s + i];
            nums[s + i] = nums[e - i];
            nums[e - i] = t;
        }
    }

    void rotate(vector<int>& nums, int k) {
        // k %= nums.size();
        // reverse(nums, 0, k - 1);
        // reverse(nums, k, nums.size() - 1);
        // reverse(nums, 0, nums.size() - 1);
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);  // 要注意交换顺序，左移右移是不一样的
    }
};
