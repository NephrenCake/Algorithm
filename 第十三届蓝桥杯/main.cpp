#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 110, O = 1 << 10, MOD = 1000000007;

LL n, m, o, ans;
int f[N][N][O];

int main() {
    cin >> n >> m;
    o = 1 << n;  // 最多可能的酒数量

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= o; ++k) {
                if (i == 0 && j == 0 && k == 2)
                    f[i][j][k] = 1;
                if (i - 1 > 0 && i - 1 < n && k % 2 == 0)
                    f[i][j][k] = f[i - 1][j][k / 2];
                if (j - 1 > 0 && j - 1 < m)
                    f[i][j][k] = (f[i][j][k] + f[i][j - 1][k + 1]) % MOD;
            }
        }
        // return 12;
    }

    for (int k = 0; k < o; ++k) {
        ans = (ans + f[n][m][k]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
