#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int nums[len];
        int p = 0, q = 0, cnt = 0;
        while (cnt < len) {
            if (p == nums1.size()) {
                nums[cnt++] = nums2[q++];
            } else if (q == nums2.size()) {
                nums[cnt++] = nums1[p++];
            } else {
                nums[cnt++] = nums1[p] < nums2[q] ? nums1[p++] : nums2[q++];
            }
        }
        int mid = len / 2 + len % 2 - 1;
        return len % 2 ? nums[mid] : ((double)nums[mid + 1] + nums[mid]) / 2;
    }
};
