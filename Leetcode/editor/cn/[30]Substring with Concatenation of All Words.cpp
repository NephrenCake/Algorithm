//You are given a string s and an array of strings words of the same length. 
//Return all starting indices of substring(s) in s that is a concatenation of each 
//word in words exactly once, in any order, and without any intervening characters. 
//
//
// You can return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: s = "barfoothefoobarman", words = ["foo","bar"]
//Output: [0,9]
//Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" 
//respectively.
//The output order does not matter, returning [9,0] is fine too.
// 
//
// Example 2: 
//
// 
//Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//Output: []
// 
//
// Example 3: 
//
// 
//Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//Output: [6,9,12]
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of lower-case English letters. 
// 1 <= words.length <= 5000 
// 1 <= words[i].length <= 30 
// words[i] consists of lower-case English letters. 
// 
// Related Topics 哈希表 字符串 滑动窗口 👍 595 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> words_map = countWords(words);
        vector<int> ans;
        int len = words[0].size();
        int tot = words.size() * len;

        for (int i = 0; i + tot <= s.size(); i++) {
            // .size() .length() 返回的都是无符号数，在减之前需要强转int
            // 不能无脑<，在进行区间时保证不越界，有可能<=。否则考虑不到 "a" ["a"]
            // i++ 而不是 i += len，没有确保子字段位置是所谓words整数倍
            string sub = s.substr(i, tot);
            // cout << "sub " << sub << endl;
            map<string, int> sub_map = countWords(sub, len);
            if (equals(sub_map, words_map))
                ans.push_back(i);
        }

        return ans;
    }

private:
    map<string, int> countWords(vector<string>& words) {
        map<string, int> ans;
        for (auto& w: words) {
            ans[w] += 1;
        }
        return ans;
    }

    map<string, int> countWords(string& words, int len) {
        map<string, int> ans;
        for (int i = 0; i < words.size(); i += len) {
            ans[words.substr(i, len)] += 1;
        }
        return ans;
    }

    bool equals(map<string, int>& a, map<string, int>& b) {
        if (a.size() != b.size())
            return false;
        for (auto& ai: a)
            if (b.find(ai.first) == b.end() || b[ai.first] != ai.second)
                return false;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
