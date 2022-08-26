#include <bits/stdc++.h>

using namespace std;

#define MaxVexNum 7
#define Max_Int 32767
#define MaxEdgeNum 12

//�ڽӾ���
typedef int VertexType, EdgeType;
typedef struct {
    VertexType vexs[MaxVexNum];  // �����
    EdgeType arcs[MaxVexNum][MaxVexNum];  // �ڽӾ����
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

void createGraph(AMGraph &g) {  // ��������ͼ
    //��ʼ�������
    for (int i = 0; i < MaxVexNum; i++)
        g.vexs[i] = i;
    for (int i = 0; i < MaxVexNum; i++)
        for (int j = 0; j < MaxVexNum; j++) {
            g.arcs[i][j] = Max_Int;  // ����
            if (i == j)
                g.arcs[i][j] = 0;
        }
    // ��ʼ����
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
    int final[MaxVexNum];  // ·���ϵ�ǰ��
    int dist[MaxVexNum];  // ���·������
    int path[MaxVexNum];  // ��Ǹ������Ƿ��Ѿ��ҵ����·��
    int v0 = 0;  // ���ĸ������
    // ��ʼ��
    for (int i = 0; i < MaxVexNum; ++i) {
        final[i] = 0;
        dist[i] = g.arcs[v0][i];  // ��ʼ�������֮��ľ���
        if (dist[i] < Max_Int) {
            path[i] = v0;
        } else {
            path[i] = -1;
        }
    }
    final[v0] = 1;  // ��ʼ����

    // dijkstra
    for (int i = 1; i < MaxVexNum; ++i) {
        int point;
        int minL = Max_Int;
        // ȷ����ǰ�����û��ǵĵ�
        for (int j = 0; j < MaxVexNum; ++j) {
            if (final[j] == 0 && dist[j] < minL) {
                minL = dist[j];
                point = j;
            }
        }
        // ������Ұ
        for (int j = 0; j < MaxVexNum; ++j) {
            int dis = g.arcs[point][j] + minL;
            if (dis < dist[j]) {
                dist[j] = dis;
                path[j] = point;
            }
        }
        final[point] = 1;
    }

    //���
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
    // ��ʼ��path[][]��A[][]����
    // path��¼·��/ǰ��/��ת�㣬A���ǳ�ʼ�ڽӾ���
    for (int i = 0; i < MaxVexNum; i++)
        for (int j = 0; j < MaxVexNum; j++) {
            path[i][j] = -1;
        }

    /**
     * ״̬��ʾ d[k][i][j]
     *      ���ϣ����д�i�����������ߵ�j�����м�ֻ�����ڵ��Ų�����k������·��
     *      ���ԣ�·�����ȵ���Сֵ
     * ״̬����
     *      ���в������ڵ�k��·�� | ���а����ڵ�k��·��
     *      min(d[k-1][i][j], d[k-1][i][k]+d[k-1][k][j])
     * �ȼ۱���
     *      min(d[i][j], d[i][k]+d[k][j])
     */
    printG(g.arcs);
    for (int k = 0; k < MaxVexNum; k++) // ��һ���Ǵ����м���
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
