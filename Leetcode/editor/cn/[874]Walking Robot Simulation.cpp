//A robot on an infinite XY-plane starts at point (0, 0) facing north. The 
//robot can receive a sequence of these three possible types of commands: 
//
// 
// -2: Turn left 90 degrees. 
// -1: Turn right 90 degrees. 
// 1 <= k <= 9: Move forward k units, one unit at a time. 
// 
//
// Some of the grid squares are obstacles. The iᵗʰ obstacle is at grid point 
//obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead 
//stay in its current location and move on to the next command. 
//
// Return the maximum Euclidean distance that the robot ever gets from the 
//origin squared (i.e. if the distance is 5, return 25). 
//
// Note: 
//
// 
// North means +Y direction. 
// East means +X direction. 
// South means -Y direction. 
// West means -X direction. 
// 
//
// 
// Example 1: 
//
// 
//Input: commands = [4,-1,3], obstacles = []
//Output: 25
//Explanation: The robot starts at (0, 0):
//1. Move north 4 units to (0, 4).
//2. Turn right.
//3. Move east 3 units to (3, 4).
//The furthest point the robot ever gets from the origin is (3, 4), which 
//squared is 3² + 4² = 25 units away.
// 
//
// Example 2: 
//
// 
//Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
//Output: 65
//Explanation: The robot starts at (0, 0):
//1. Move north 4 units to (0, 4).
//2. Turn right.
//3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1,
// 4).
//4. Turn left.
//5. Move north 4 units to (1, 8).
//The furthest point the robot ever gets from the origin is (1, 8), which 
//squared is 1² + 8² = 65 units away.
// 
//
// Example 3: 
//
// 
//Input: commands = [6,-1,-1,6], obstacles = []
//Output: 36
//Explanation: The robot starts at (0, 0):
//1. Move north 6 units to (0, 6).
//2. Turn right.
//3. Turn right.
//4. Move south 6 units to (0, 0).
//The furthest point the robot ever gets from the origin is (0, 6), which 
//squared is 6² = 36 units away.
// 
//
// 
// Constraints: 
//
// 
// 1 <= commands.length <= 10⁴ 
// commands[i] is either -2, -1, or an integer in the range [1, 9]. 
// 0 <= obstacles.length <= 10⁴ 
// -3 * 10⁴ <= xi, yi <= 3 * 10⁴ 
// The answer is guaranteed to be less than 2³¹. 
// 
// Related Topics 数组 模拟 👍 161 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int robotSim(vector<int> &commands, vector <vector<int>> &obstacles) {
        // 构造可哈希结构
        // (-200, 400)
        // 1. string: "-200,400"  推荐直接用string存pair
        // 2. long long: (-200, 400) -> (-200 + 30000, 400 + 30000) -> (-200 + 30000) * 60000 + (400 + 30000)
        set <string> blockers;
        for (auto &obstacle: obstacles) {
            blockers.insert(calHah(obstacle[0], obstacle[1]));
        }

        // 方向数组   N  E  S  W
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0;
        int dir = 0;
        int ans = 0;  // 维护最大距离
        for (int cmd: commands) {
            if (cmd >= 1 && cmd <= 9) {
                // 1. 处理步距
                for (int i = 0; i < cmd; ++i) {
                    // 尝试走向下一处位置
                    int nextx = x + dx[dir];
                    int nexty = y + dy[dir];
                    // 查询下一个位置是否存在障碍物
                    if (blockers.find(calHah(nextx, nexty)) != blockers.end()) {
                        break;
                    }
                    // 更新位置
                    x = nextx;
                    y = nexty;
                    ans = max(ans, x * x + y * y);
                }
            } else {
                // 2. 处理方向
                if (cmd == -1) {
                    // N -> E -> S -> W
                    dir = (dir + 1) % 4;
                } else {
                    dir = (dir - 1 + 4) % 4;
                }
            }
        }
        return ans;
    }

private:
    string calHah(int a, int b) {
        return to_string(a) + "," + to_string(b);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
