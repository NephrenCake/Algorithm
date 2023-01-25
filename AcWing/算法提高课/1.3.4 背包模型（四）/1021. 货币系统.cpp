#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20, M = 3010;
int n, m, a[N];
long long f[N][M];  // 注意用longlong

int main() {
    cin >> n >> m;  // n种面值 组成面值为m
    for (int i = 1; i<= n; i++) cin >> a[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int r = 0; r < a[i]; r++) {
            f[i][r] = f[i - 1][r];
            for (int j = r + a[i]; j <= m; j += a[i]) {
                f[i][j] = f[i - 1][j] + f[i][j - a[i]];
            }
        }
    cout << f[n][m];
}
