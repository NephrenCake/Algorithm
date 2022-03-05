//In this problem, a tree is an undirected graph that is connected and has no 
//cycles. 
//
// You are given a graph that started as a tree with n nodes labeled from 1 to 
//n, with one additional edge added. The added edge has two different vertices 
//chosen from 1 to n, and was not an edge that already existed. The graph is 
//represented as an array edges of length n where edges[i] = [ai, bi] indicates that there 
//is an edge between nodes ai and bi in the graph. 
//
// Return an edge that can be removed so that the resulting graph is a tree of 
//n nodes. If there are multiple answers, return the answer that occurs last in 
//the input. 
//
// 
// Example 1: 
//
// 
//Input: edges = [[1,2],[1,3],[2,3]]
//Output: [2,3]
// 
//
// Example 2: 
//
// 
//Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
//Output: [1,4]
// 
//
// 
// Constraints: 
//
// 
// n == edges.length 
// 3 <= n <= 1000 
// edges[i].length == 2 
// 1 <= ai < bi <= edges.length 
// ai != bi 
// There are no repeated edges. 
// The given graph is connected. 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (vector<int>& e : edges) {
            int u = e[0], v = e[1];
            n = max(n, u);
            n = max(n, v);
        }  // 初始化找最大n值

        // 模板：出边数组初始化
        edge = vector<vector<int>>(n + 1, vector<int>());
        visit = vector<bool>(n + 1, false);
        hasCycle = false;

        for (vector<int>& e : edges) {
            // 为了找到形成环的那一条边，所以才加一条边查一次
            int u = e[0], v = e[1];
            edge[u].push_back(v);
            edge[v].push_back(u);
            dfs(u, 0);
            if (hasCycle)
                return e;
        }
        return {};
    }

private:
    int n;
    vector<vector<int>> edge;
    vector<bool> visit;
    bool hasCycle;

    // 模板：DFS无向图找环
    void dfs(int x, int fa) {
        visit[x] = true;
        for (int y : edge[x]) {
            if (y == fa)
                continue;  // 无向图会返回父节点，因此跳过，该无向边不算环
            if (!visit[y])
                dfs(y, x);  // 发现没走过的子节点
            else
                hasCycle = true;  // 发现子节点已经走过，在无向图中必出现环
        }
        visit[x] = false;  // 还原现场
    }
};
//leetcode submit region end(Prohibit modification and deletion)
