//A gene string can be represented by an 8-character long string, with choices 
//from 'A', 'C', 'G', and 'T'. 
//
// Suppose we need to investigate a mutation from a gene string start to a gene 
//string end where one mutation is defined as one single character changed in the 
//gene string. 
//
// 
// For example, "AACCGGTT" --> "AACCGGTA" is one mutation. 
// 
//
// There is also a gene bank bank that records all the valid gene mutations. A 
//gene must be in bank to make it a valid gene string. 
//
// Given the two gene strings start and end and the gene bank bank, return the 
//minimum number of mutations needed to mutate from start to end. If there is no 
//such a mutation, return -1. 
//
// Note that the starting point is assumed to be valid, so it might not be 
//included in the bank. 
//
// 
// Example 1: 
//
// 
//Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
//Output: 1
// 
//
// Example 2: 
//
// 
//Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA",
//"AAACGGTA"]
//Output: 2
// 
//
// Example 3: 
//
// 
//Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC",
//"AACCCCCC"]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// start.length == 8 
// end.length == 8 
// 0 <= bank.length <= 10 
// bank[i].length == 8 
// start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T']. 
//
// 
// Related Topics 广度优先搜索 哈希表 字符串 👍 101 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMutation(string start, string end, vector <string>& bank) {
        const char gene[4] = {'A', 'C', 'G', 'T'};  // 常数数组
        map<string, bool> visit;
        for (string& b: bank) {
            visit[b] = false;
        }  // 同时表示该key的存在，以及是否被访问
        queue <pair<string, int>> q;
        q.push(make_pair(start, 0));  // 同时表示该字符串与层级
        // visit[start] = true;
        while (!q.empty()) {
            string s = q.front().first;
            int lv = q.front().second;
            q.pop();  // 取队头
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (s[i] == gene[j]) {
                        continue;  // 跳过自己
                    }
                    string ns = s;
                    ns[i] = gene[j];
                    if (visit.find(ns) == visit.end()) {
                        continue;  // 不存在于基因库
                    }
                    if (!visit[ns]) {
                        q.push(make_pair(ns, lv + 1));
                        visit[ns] = true;  // 未访问入队
                    }
                    if (ns == end) {
                        return lv + 1;  // 找到
                    }
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
