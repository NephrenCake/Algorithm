//Given an m x n integers matrix, return the length of the longest increasing 
//path in matrix. 
//
// From each cell, you can either move in four directions: left, right, up, or 
//down. You may not move diagonally or move outside the boundary (i.e., wrap-
//around is not allowed). 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
// 
//
// Example 2: 
//
// 
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally 
//is not allowed.
// 
//
// Example 3: 
//
// 
//Input: matrix = [[1]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 2³¹ - 1 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 记忆化搜索 动态规划 👍 580 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


// DFS 记忆化
class Solution {
public:
    int longestIncreasingPath(vector <vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        answer = vector < vector < int >> (m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, howFar(matrix, i, j));  // 每个格子都要作为起点
        return ans;
    }

    // 子问题：从(x,y)出发能走多远
    int howFar(vector <vector<int>>& matrix, int x, int y) {
        if (answer[x][y] != -1)
            return answer[x][y];  // 已经走过
        answer[x][y] = 1;  // 至少为1
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;  // 走向下一个位置之前检查越界
            if (matrix[nx][ny] > matrix[x][y])
                answer[x][y] = max(answer[x][y], howFar(matrix, nx, ny) + 1);  // 递归
            // cout << x << "," << y << ":" << answer[x][y] << endl;
        }
        return answer[x][y];
    }

    int m;
    int n;
    vector <vector<int>> answer;  // 不仅保留了计算结果，还起到和visit一样的效果
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
};
//leetcode submit region end(Prohibit modification and deletion)
