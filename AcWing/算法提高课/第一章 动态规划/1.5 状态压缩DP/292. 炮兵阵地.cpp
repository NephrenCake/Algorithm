#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110, M = 1 << 10;
int n, m, a[N], st[M], f[M][M], g[M][M], ones[M];
vector<int> val[M][M];

int count(int x) {
    int res = 0;
    while (x) res++, x -= x & (-x);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char t;
            cin >> t;
            a[i] = (a[i] << 1) + (t == 'H');
        }
    // 预处理每行的合法状态
    for (int i = 0; i < 1 << m; i++)
        ones[i] = count(i);
    for (int i = 0; i < 1 << m; i++)
        if (((i >> 1) & i) == 0 && ((i >> 2) & i) == 0)
            st[i] = 1;
    // 预处理前前行的合法状态
    for (int i = 0; i < 1 << m; i++)
        if (st[i])
            for (int j = 0; j < 1 << m; j++)
                if (st[j] && (i & j) == 0)
                    for (int k = 0; k < 1 << m; k++)
                        if (st[k] && ((i & k) | (j & k)) == 0)
                            val[i][j].push_back(k);
    // dp  f[i][j][k] 前i行，第i行状态为j，第i-1行状态为k，的最多炮兵数量
    for (int i = 1; i <= n + 2; i++) {
        memcpy(g, f, sizeof f);
        for (int j = 0; j < 1 << m; j++)
            if (st[j] && (j & a[i]) == 0)
                for (int k = 0; k < 1 << m; k++)
                    if (st[k] && (k & a[i - 1]) == 0 && (j & k) == 0)
                        for (int it: val[j][k])
                            f[j][k] = max(f[j][k], g[k][it] + ones[j]);
    }
    cout << f[0][0];
}
