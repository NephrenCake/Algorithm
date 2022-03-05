//Given a string containing digits from 2-9 inclusive, return all possible 
//letter combinations that the number could represent. Return the answer in any order. 
//
//
// A mapping of digit to letters (just like on the telephone buttons) is given 
//below. Note that 1 does not map to any letters. 
//
// 
//
// 
// Example 1: 
//
// 
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// Example 2: 
//
// 
//Input: digits = ""
//Output: []
// 
//
// Example 3: 
//
// 
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//
// 
// Constraints: 
//
// 
// 0 <= digits.length <= 4 
// digits[i] is a digit in the range ['2', '9']. 
// 
// Related Topics 哈希表 字符串 回溯 👍 1693 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
            index=0
            str=""
       a/      b|      c\
    index=1   index=1  index=1
    str="a"   str="b"  str="c"
  /   |   \   ...
  ...
 */
class Solution {
public:
    vector <string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        edges['2'] = "abc";
        edges['3'] = "def";
        edges['4'] = "ghi";
        edges['5'] = "jkl";
        edges['6'] = "mno";
        edges['7'] = "pqrs";
        edges['8'] = "tuv";
        edges['9'] = "wxyz";
        dfs(digits, 0);
        return ans;
    }

private:
    map<char, string> edges;
    string s;
    vector <string> ans;

    void dfs(string& digits, int index) {
        // 边界条件
        if (digits.size() == index) {
            ans.push_back(s);
            return;
        }
        // 考虑所有出边
        for (char ch: edges[digits[index]]) {
            s.push_back(ch);
            dfs(digits, index + 1);
            s.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
