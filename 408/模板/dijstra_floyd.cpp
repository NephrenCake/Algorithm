#include <bits/stdc++.h>

using namespace std;

#define MaxVexNum 7
#define Max_Int 32767
#define MaxEdgeNum 12

//邻接矩阵
typedef int VertexType, EdgeType;
typedef struct {
    VertexType vexs[MaxVexNum];  // 顶点表
    EdgeType arcs[MaxVexNum][MaxVexNum];  // 邻接矩阵表
} AMGraph;

void printG(int G[MaxVexNum][MaxVexNum]) {
    for (int i = 0; i < MaxVexNum; i++) {
        for (int j = 0; j < MaxVexNum; j++)
            if (G[i][j] == Max_Int)
                cout << "_" << " ";
            else
                cout << G[i][j] << " ";
        cout << endl;
    }
}

void createGraph(AMGraph &g) {  // 创建无向图
    //初始化顶点表
    for (int i = 0; i < MaxVexNum; i++)
        g.vexs[i] = i;
    for (int i = 0; i < MaxVexNum; i++)
        for (int j = 0; j < MaxVexNum; j++) {
            g.arcs[i][j] = Max_Int;  // 无穷
            if (i == j)
                g.arcs[i][j] = 0;
        }
    // 初始化边
    g.arcs[0][1] = 4;
    g.arcs[0][2] = 6;
    g.arcs[0][3] = 6;
    g.arcs[1][2] = 1;
    g.arcs[3][2] = 2;
    g.arcs[1][4] = 7;
    g.arcs[2][4] = 6;
    g.arcs[2][5] = 4;
    g.arcs[3][5] = 5;
    g.arcs[5][4] = 1;
    g.arcs[4][6] = 6;
    g.arcs[5][6] = 8;
}

void Dijkstra(AMGraph g) {
    int final[MaxVexNum];  // 路径上的前驱
    int dist[MaxVexNum];  // 最短路径长度
    int path[MaxVexNum];  // 标记各顶点是否已经找到最短路径
    int v0 = 0;  // 从哪个点出发
    // 初始化
    for (int i = 0; i < MaxVexNum; ++i) {
        final[i] = 0;
        dist[i] = g.arcs[v0][i];  // 起始点与各点之间的距离
        if (dist[i] < Max_Int) {
            path[i] = v0;
        } else {
            path[i] = -1;
        }
    }
    final[v0] = 1;  // 初始顶点

    // dijkstra
    for (int i = 1; i < MaxVexNum; ++i) {
        int point;
        int minL = Max_Int;
        // 确定当前最近且没标记的点
        for (int j = 0; j < MaxVexNum; ++j) {
            if (final[j] == 0 && dist[j] < minL) {
                minL = dist[j];
                point = j;
            }
        }
        // 更新视野
        for (int j = 0; j < MaxVexNum; ++j) {
            int dis = g.arcs[point][j] + minL;
            if (dis < dist[j]) {
                dist[j] = dis;
                path[j] = point;
            }
        }
        final[point] = 1;
    }

    //输出
    printf("       ");
    for (int i = 0; i < MaxVexNum; i++) printf("%d  ", i);
    printf("\ndist[]:");
    for (int i = 0; i < MaxVexNum; i++) printf("%d  ", dist[i]);
    printf("\npath[]:");
    for (int i = 0; i < MaxVexNum; i++) printf("%d  ", path[i]);
    printf("\nfinal[]:");
    for (int i = 0; i < MaxVexNum; i++) printf("%d  ", final[i]);
}

void Floyd(AMGraph g) {
    int path[MaxVexNum][MaxVexNum];
    // 初始化path[][]和A[][]数组
    // path记录路径/前驱/中转点，A就是初始邻接矩阵
    for (int i = 0; i < MaxVexNum; i++)
        for (int j = 0; j < MaxVexNum; j++) {
            path[i][j] = -1;
        }

    /**
     * 状态表示 d[k][i][j]
     *      集合：所有从i出发，最终走到j，且中间只经过节点编号不超过k的所有路径
     *      属性：路径长度的最小值
     * 状态计算
     *      所有不包含节点k的路径 | 所有包含节点k的路径
     *      min(d[k-1][i][j], d[k-1][i][k]+d[k-1][k][j])
     * 等价变形
     *      min(d[i][j], d[i][k]+d[k][j])
     */
    printG(g.arcs);
    for (int k = 0; k < MaxVexNum; k++) // 第一层是代表中间结点
        for (int i = 0; i < MaxVexNum; i++)
            for (int j = 0; j < MaxVexNum; j++)
                if (g.arcs[i][j] > g.arcs[i][k] + g.arcs[k][j]) {
                    printf("i(%d)->j(%d): %d\n", i, j, g.arcs[i][j]);
                    printf("i(%d)->k(%d)->j(%d): %d\n", i, k, j, g.arcs[i][k] + g.arcs[k][j]);
                    g.arcs[i][j] = g.arcs[i][k] + g.arcs[k][j];
                    path[i][j] = k;
                    printG(g.arcs);
                }
}

int main() {
    AMGraph g;
    createGraph(g);
    // Dijkstra(g);
    Floyd(g);
}
