//There are a total of numCourses courses you have to take, labeled from 0 to 
//numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai,
// bi] indicates that you must take course bi first if you want to take course ai.
// 
//
// 
// For example, the pair [0, 1], indicates that to take course 0 you have to 
//first take course 1. 
// 
//
// Return true if you can finish all courses. Otherwise, return false. 
//
// 
// Example 1: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: true
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0. So it is possible.
// 
//
// Example 2: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0, and to take course 0 you 
//should also have finished course 1. So it is impossible.
// 
//
// 
// Constraints: 
//
// 
// 1 <= numCourses <= 10⁵ 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// All the pairs prerequisites[i] are unique. 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 1096 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 拓扑排序：有向图是否有环
    bool canFinish(int numCourses, vector <vector<int>> &prerequisites) {
        n = numCourses;
        edges = vector<vector<int>>(n, vector<int>());  // 出边数组初始化
        inDeg = vector<int>(n, 0);
        for (vector<int> pre: prerequisites) {
            addEdge(pre[1], pre[0]);
        }
        // 排序
        return topSort() == numCourses;
    }

private:
    int n;
    vector<vector<int>> edges;
    vector<int> inDeg;

    // 有向图找环模板
    int topSort() {
        int learned = 0;
        // 拓扑排序基于BFS，需要队列
        queue<int> q;
        // 从所有的0入度点出发
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0)
                q.push(i);
        }
        // 执行BFS
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            learned++;
            // 考虑所有x的出边
            for (int y: edges[x]) {
                inDeg[y]--;  // 去掉约束关系
                if (inDeg[y] == 0)
                    q.push(y);  // 入度为0，可学
            }
        }
        return learned;
    }

    void addEdge(int x, int y) {
        edges[x].push_back(y);
        inDeg[y]++;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
