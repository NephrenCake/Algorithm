#include <iostream>

using namespace std;

const int N = 60, MOD = 1e9 + 7;
int n, ne[N], f[N][N], ans, len;
string a;

int main() {
    cin >> n >> a;
    len = a.size(), a = " " + a;

    for (int i = 2, j = 0; i <= len; i++) {
        while (j && a[i] != a[j + 1]) j = ne[j];
        if (a[i] == a[j + 1]) j++;
        ne[i] = j;
    }

    // f[i][j] 已经生成了i位，并且第i位匹配在ne[j]时，的方案数
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= len; j++)
            for (char k = 'a'; k <= 'z'; k++) {
                int u = j;
                while (u && k != a[u + 1]) u = ne[u];
                if (k == a[u + 1]) u++;
                if (u < len) f[i][u] = (f[i][u] + f[i - 1][j]) % MOD;
            }
    for (int i = 0; i < len; i++) ans = (ans + f[n][i]) % MOD;
    cout << ans;
}
