#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/majority-element/solution/

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int nums
        unordered_map<int, int> cnt;
        for (auto n : nums)
            cnt[n]++;
        for (auto kv: cnt)
            if (kv.second > nums.size() / 2)
                return kv.first;
        return -1;
    }
};
