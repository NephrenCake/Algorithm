//A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
//the diagram below). 
//
// The robot can only move either down or right at any point in time. The robot 
//is trying to reach the bottom-right corner of the grid (marked 'Finish' in the 
//diagram below). 
//
// Now consider if some obstacles are added to the grids. How many unique paths 
//would there be? 
//
// An obstacle and space is marked as 1 and 0 respectively in the grid. 
//
// 
// Example 1: 
//
// 
//Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//Output: 2
//Explanation: There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom-right corner:
//1. Right -> Right -> Down -> Down
//2. Down -> Down -> Right -> Right
// 
//
// Example 2: 
//
// 
//Input: obstacleGrid = [[0,1],[0,0]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// m == obstacleGrid.length 
// n == obstacleGrid[i].length 
// 1 <= m, n <= 100 
// obstacleGrid[i][j] is 0 or 1. 
// 
// Related Topics 数组 动态规划 矩阵 👍 717 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 法一：深搜
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memory = vector<vector<long long>>(obstacleGrid.size() + 1,
                vector<long long>(obstacleGrid[0].size() + 1, -1));
        memory[1][1] = 1;
        for (int i = 0; i < memory.size(); ++i)
            for (int j = 0; j < memory[0].size(); ++j)
                if (i == 0 || j == 0 || obstacleGrid[i - 1][j - 1] == 1)
                    memory[i][j] = 0;
        return dfs(obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size());
    }

    long long dfs(vector<vector<int>>& obstacleGrid, int x, int y) {
        if (memory[x][y] != -1)
            return memory[x][y];
        memory[x][y] = dfs(obstacleGrid, x - 1, y) + dfs(obstacleGrid, x, y - 1) ;
        return memory[x][y];
    }

    vector<vector<long long>> memory;
};

// 法二：动规
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() + 1, n = obstacleGrid[0].size() + 1;
        vector<vector<int>> memory = vector<vector<int>>(m, vector<int>(obstacleGrid[0].size() + 1, -1));
        memory[1][1] = 1;
        for (int i = 0; i < obstacleGrid.size() + 1; ++i)
            for (int j = 0; j < obstacleGrid[0].size() + 1; ++j)
                if (i == 0 || j == 0 || obstacleGrid[i - 1][j - 1] == 1)
                    memory[i][j] = 0;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (memory[i][j] == -1)
                    memory[i][j] = memory[i - 1][j] + memory[i][j - 1];
        return memory[m - 1][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
