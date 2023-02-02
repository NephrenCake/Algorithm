#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 20, M = 1 << N;

int n, f[M][N], g[N][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;  // i=0为起点
    for (int i = 0; i < 1 << n; i++)  // 经过节点的状态i
        for (int j = 0; j < n; j++)  // 最终到达节点j
            if (i >> j & 1)  // 要达到j节点，首先所经过的点集状态i必须包含j，其他为非法
                for (int k = 0; k < n; k++)  // 走到节点j之前一个节点k所经历的最短距离
                    if ((i - (1 << j)) >> k & 1)  // 要达到k节点，首先所经过的点集状态i(除去j)必须包含k，其他为非法
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + g[k][j]);
    cout << f[(1 << n) - 1][n - 1];  // 所有点都走过了,且终点是n-1的最短距离
}
