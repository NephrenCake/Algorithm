//Given an array of strings strs, group the anagrams together. You can return 
//the answer in any order. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a 
//different word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2: 
// Input: strs = [""]
//Output: [[""]]
// Example 3: 
// Input: strs = ["a"]
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] consists of lowercase English letters. 
// 
// Related Topics 哈希表 字符串 排序 👍 975 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 只要看到不要求顺序的情形，都要想到自行指定其排序是否能变得简单
        map<string, vector<string>> group;
        for (string& str: strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            group[copy].push_back(str);
            // cout << str << " -> " << copy << endl;
        }

        vector<vector<string>> ans;
        for (auto pr: group) {
            ans.push_back(pr.second);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
