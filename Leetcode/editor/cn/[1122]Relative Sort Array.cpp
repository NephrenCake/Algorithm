//Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all 
//elements in arr2 are also in arr1. 
//
// Sort the elements of arr1 such that the relative ordering of items in arr1 
//are the same as in arr2. Elements that do not appear in arr2 should be placed at 
//the end of arr1 in ascending order. 
//
// 
// Example 1: 
//
// 
//Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//Output: [2,2,2,1,4,3,3,9,6,7,19]
// 
//
// Example 2: 
//
// 
//Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
//Output: [22,28,8,6,17,44]
// 
//
// 
// Constraints: 
//
// 
// 1 <= arr1.length, arr2.length <= 1000 
// 0 <= arr1[i], arr2[i] <= 1000 
// All the elements of arr2 are distinct. 
// Each arr2[i] is in arr1. 
// 
// Related Topics 数组 哈希表 计数排序 排序 👍 200 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count = vector<int>(1001, 0);  // 不能用hashmap，有序的map反而会提升复杂度
        vector<int> ans;
        for (int& n: arr1) {
            count[n]++;
        }
        for (int& n: arr2) {
            while (count[n] > 0) {
                ans.push_back(n);
                count[n]--;  // 在内部操作数据，要注意外部的判断是否会变化
            }
        }
        for (int i = 0; i < count.size(); ++i) {
            while (count[i] > 0) {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
