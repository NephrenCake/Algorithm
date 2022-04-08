#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 2050, INF = 0x3f3f3f;

int n = 2021;      // 点的数量
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定
int g[N][N];  // 存储每条边

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i ++ ){
        int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int gcd(int a, int b) {  // 最大公约数
    return b ? gcd(b, a % b) : a;
}

int main() {
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (abs(i - j) <= 21) {
                int wi = i * j / gcd(i, j);
                g[i][j] = wi;
                g[j][i] = wi;
                // cout << wi << endl;
            }
        }
    }
    cout << dijkstra();
}
