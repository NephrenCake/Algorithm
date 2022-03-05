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
// Return the ordering of courses you should take to finish all courses. If 
//there are many valid answers, return any of them. If it is impossible to finish all 
//courses, return an empty array. 
//
// 
// Example 1: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: [0,1]
//Explanation: There are a total of 2 courses to take. To take course 1 you 
//should have finished course 0. So the correct course order is [0,1].
// 
//
// Example 2: 
//
// 
//Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//Output: [0,2,1,3]
//Explanation: There are a total of 4 courses to take. To take course 3 you 
//should have finished both courses 1 and 2. Both courses 1 and 2 should be taken 
//after you finished course 0.
//So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3
//].
// 
//
// Example 3: 
//
// 
//Input: numCourses = 1, prerequisites = []
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= numCourses * (numCourses - 1) 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// ai != bi 
// All the pairs [ai, bi] are distinct. 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 557 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector <vector<int>>& prerequisites) {
        n = numCourses;
        // 出边数组初始化，n个空list
        edges = vector < vector < int >> (n, vector<int>());
        inDeg = vector<int>(n, 0);
        for (vector<int>& pre : prerequisites) {
            // 加边模板
            addEdge(pre[1], pre[0]);
        }
        auto ans = topsort();
        if (ans.size() < n)
            return {}; // 不能完成所有课程
        return ans;
    }

private:
    int n;
    vector <vector<int>> edges;
    vector<int> inDeg; // in degree 入度

    // 有向图找环 模板（拓扑排序）
    // 返回学的课程数
    vector<int> topsort() {
        vector<int> order;
        // 拓扑排序基于BFS，需要队列
        queue<int> q;
        // 从所有零入度点出发
        for (int i = 0; i < n; i++)
            if (inDeg[i] == 0)
                q.push(i);
        // 执行BFS
        while (!q.empty()) {
            int x = q.front(); // 取队头（这门课学了）
            q.pop();
            order.push_back(x);
            // 考虑x的所有出边
            for (int y : edges[x]) {
                inDeg[y]--; // 去掉约束关系
                if (inDeg[y] == 0)
                    q.push(y);
            }
        }
        return order;
    }

    void addEdge(int x, int y) {
        edges[x].push_back(y);
        inDeg[y]++;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
