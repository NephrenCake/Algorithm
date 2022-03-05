//Given an integer array nums, return the number of reverse pairs in the array. 
//
//
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 
//2 * nums[j]. 
//
// 
// Example 1: 
// Input: nums = [1,3,2,3,1]
//Output: 2
// Example 2: 
// Input: nums = [2,4,3,5,1]
//Output: 3
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 326 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        calculate(nums, l, mid, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> t = vector<int>(r - l + 1, 0);
        int i = l, j = m + 1, p = 0;
        for (int k = 0; k < t.size(); k++) {
            if (j > r || nums[i] <= nums[j] && i <= m)
                t[k] = nums[i++];
            else
                t[k] = nums[j++];
        }
        for (int k = 0; k < t.size(); k++) {  // 拷回原数组
            nums[l + k] = t[k];
        }
    }

    void calculate(vector<int>& nums, int l, int m, int r) {
        for (int i = l, j = m; i <= m; i++) {
            while (j < r && nums[i] > 2L * nums[j + 1]) j++;
                ans += j - m;
        }
    }

    int ans;
};
//leetcode submit region end(Prohibit modification and deletion)
