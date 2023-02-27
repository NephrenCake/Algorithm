#include <iostream>
#include <cstring>

using namespace std;

const int N = 21;
int n, a[N][N], f[1 << N][N];  // 经过状态i，且最终到达j，的最短路径长度

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 1; i < (1 << n); i++)
        if (i & 1)
            for (int j = 1; j < n; j++)
                if (i >> j & 1)
                    for (int k = 0; k < n; k++)
                        if ((i - (1 << j)) >> k & 1)
                            f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);
    cout << f[(1 << n) - 1][n - 1];
}
