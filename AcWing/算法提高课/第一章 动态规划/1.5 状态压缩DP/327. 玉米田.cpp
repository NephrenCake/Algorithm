#include <iostream>
#include <vector>

using namespace std;

const int N = 14, M = 1 << N, MOD = 1e8;
int n, m, a[N], st[M], f[N][M];
vector<int> val[M];

int main() {
    cin >> n >> m;
    for (int i = 1, t; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> t;
            a[i] = (a[i] << 1) + !t;
        }
    // 预处理每一行的合法状态
    for (int i = 0; i < 1 << m; i++)
        if (((i >> 1) & i) == 0)
            st[i] = 1;
    // 预处理前一行的合法状态
    for (int i = 0; i < 1 << m; i++)
        if (st[i])
            for (int j = 0; j < 1 << m; j++)
                if (st[j] && (i & j) == 0)
                    val[i].push_back(j);
    // dp  f[i][j] 前i行，且第i行种植状态为j的种植方法
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < 1 << m; j++)
            if (st[j] && (j & a[i]) == 0)
                for (auto it: val[j])
                    if ((it & a[i - 1]) == 0)
                        f[i][j] = (f[i][j] + f[i - 1][it]) % MOD;
    cout << f[n + 1][0];
}
