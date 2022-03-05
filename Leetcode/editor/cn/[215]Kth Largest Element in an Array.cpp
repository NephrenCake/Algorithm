//Given an integer array nums and an integer k, return the kᵗʰ largest element 
//in the array. 
//
// Note that it is the kᵗʰ largest element in the sorted order, not the kᵗʰ 
//distinct element. 
//
// 
// Example 1: 
// Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
// Example 2: 
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
// 
// Constraints: 
//
// 
// 1 <= k <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 1463 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 第K大，等于（排序后下标从0开始）第N-K小
        // 复杂度 N + N/2 + N/4 + ... = 2N = O(N)
        return quickSort(nums, nums.size() - k, 0, nums.size() - 1);
    }

private:
    int quickSort(vector<int>& nums, int k, int l, int r) {
        if (l == r)
            return nums[r];
        int p = partition(nums, l, r);
        if (k <= p)
            return quickSort(nums, k, l, p);
        else
            return quickSort(nums, k, p + 1, r);
    }

    int partition(vector<int>& nums, int l, int r) {
        int p = l + rand() % (r - l + 1);  // 意义是计算随机取一个标准的下标
        int pv = nums[p];
        while (l <= r) {
            while (nums[l] < pv)
                l++;
            while (nums[r] > pv)
                r--;
            if (l == r)
                break;  // 防止中途破坏条件
            if (l < r) {  // 加一层保护
                int temp = nums[l]; nums[l] = nums[r]; nums[r] = temp;
                l++; r--;
            }
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
