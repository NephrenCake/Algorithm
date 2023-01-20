#include <iostream>
#include <algorithm>

using namespace std;

const int N = 60;
int m, n, a[N][N], f[2 * N][N][N];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int k = 2; k <= n + m; k++)
        // 注意：循环中要保证 1 <= i <= m && 1 <= j <= n
        // 变形为 1 <= i <= m && 1 <= k - i <= n
        // 变形为 1 <= i <= m && i <= k - 1 && k - n <= i
        // 变形为 max(1, k - n) <= i <= min(m, k - 1)
        for (int i1 = max(1, k - n); i1 <= min(m, k - 1); i1++)
            for (int i2 = max(1, k - n); i2 <= min(m, k - 1); i2++) {
                int t = i1 == i2 ? a[i1][k - i1] : a[i1][k - i1] + a[i2][k - i2];
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2 - 1] + t);
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2 - 1] + t);
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2] + t);
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2] + t);
            }
    cout << f[n + m][m][m];
}
