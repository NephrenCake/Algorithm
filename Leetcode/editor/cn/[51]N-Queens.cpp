//The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
//such that no two queens attack each other. 
//
// Given an integer n, return all distinct solutions to the n-queens puzzle. 
//You may return the answer in any order. 
//
// Each solution contains a distinct board configuration of the n-queens' 
//placement, where 'Q' and '.' both indicate a queen and an empty space, respectively. 
//
// 
// Example 1: 
//
// 
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as 
//shown above
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: [["Q"]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 9 
// 
// Related Topics 数组 回溯 👍 1158 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<string>> solveNQueens(int n) {
        this->n = n;
        usedCol = vector<bool>(n, false);
        // dsf
        find(0);
        // n = 4
        // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
        vector <vector<string>> result;
        for (vector<int>& per : ans) {
            vector <string> res;
            for (int row = 0; row < n; ++row) {
                int col = per[row];
                string str(n, '.');  // n个.
                str[col] = 'Q';
                res.push_back(str);
            }
            result.push_back(res);
        }
        return result;
    }

    void find(int row) {
        if (n == row) {
            // for (int x : s)
            //    cout << x;
            // cout << endl;
            ans.push_back(s);
            return;
        }
        for (int col = 0; col < n; ++col) {
            // 初始化为false，可以直接[]访问
            if (!usedCol[col] && !usedIPlusJ[row + col] && !usedIMinusJ[row - col]) {
                // 标记
                usedCol[col] = true;
                usedIPlusJ[row + col] = true;
                usedIMinusJ[row - col] = true;
                s.push_back(col);
                // 递归
                find(row + 1);
                // 还原
                s.pop_back();
                usedCol[col] = false;
                usedIPlusJ[row + col] = false;
                usedIMinusJ[row - col] = false;
            }
        }
    }

private:
    int n;
    vector <vector<int>> ans;
    vector<int> s;
    vector<bool> usedCol;
    map<int, bool> usedIPlusJ;
    map<int, bool> usedIMinusJ;
};
/*
i+j
i-j


i-j=0
\
(1,1)
(2,2)
(3,3)
(4,4)

i-j=-1
(1,2)
(2,3)
(3,4)

i+j=5
/
(1,4)
(2,3)
(3,2)
(4,1)
*/
//leetcode submit region end(Prohibit modification and deletion)
