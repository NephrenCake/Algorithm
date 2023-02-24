#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << 20;
int n, a[N][N], f[M][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    // f[i][j] 从0走到j，且最终状态为i的，所有路径最小值
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)  // 先循环最终状态i
        for (int j = 0; j < n; j++)  // 再循环最终到达节点j
            if (i >> j & 1)  // 要达到j节点，首先所经过的点集状态i必须包含j，其他为非法
                for (int k = 0; k < n; k++)  // 遍历每个走向j的k
                    if ((i - (1 << j)) >> k & 1)  // 要达到k节点，首先所经过的点集状态i(除去j)必须包含k，其他为非法
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);
    cout << f[(1 << n) - 1][n - 1];  // 所有点都走过了,且终点是n-1的最短距离
}
