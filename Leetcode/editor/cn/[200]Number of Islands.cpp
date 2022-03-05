//Given an m x n 2D binary grid grid which represents a map of '1's (land) and 
//'0's (water), return the number of islands. 
//
// An island is surrounded by water and is formed by connecting adjacent lands 
//horizontally or vertically. You may assume all four edges of the grid are all 
//surrounded by water. 
//
// 
// Example 1: 
//
// 
//Input: grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//Output: 1
// 
//
// Example 2: 
//
// 
//Input: grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] is '0' or '1'. 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1512 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 深搜
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         visit = vector<vector<bool>>(m, vector<bool>(n, false));
//         int ans = 0;
//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 if (grid[i][j] == '1' && !visit[i][j]) {
//                     dfs(grid, i, j);
//                     ans++;
//                 }
//         return ans;
//     }
//
//     void dfs(vector<vector<char>>& grid, int x, int y) {
//         visit[x][y] = true;
//         // 四个方向
//         for (int i = 0; i < 4; ++i) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             // 任何时候访问数组前，判断合法性
//             if (nx < 0 || nx >= m || ny < 0 || ny >= n)
//                 continue;
//             if (grid[nx][ny] == '1' && !visit[nx][ny])
//                 dfs(grid, nx, ny);
//         }
//     }
//
// private:
//     int m;
//     int n;
//     vector<vector<bool>> visit;
//     const int dx[4] = {-1, 0, 0, 1};
//     const int dy[4] = {0, -1, 1, 0};
// };

// 广搜
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1' && !visit[i][j]) {
                    bfs(grid, i, j);
                    ans++;
                }
        return ans;
    }

    void bfs(vector<vector<char>>& grid, int sx, int sy) {
        queue<pair<int, int>> q;
        q.push(make_pair(sx, sy));
        visit[sx][sy] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (grid[nx][ny] == '1' && !visit[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = true;  // 必须在压入的时候标记
                }
            }
        }
    }

private:
    int m;
    int n;
    vector<vector<bool>> visit;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
};
//leetcode submit region end(Prohibit modification and deletion)
