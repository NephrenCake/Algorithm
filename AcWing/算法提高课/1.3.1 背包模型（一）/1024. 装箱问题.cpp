#include <iostream>
#include <algorithm>

using namespace std;
const int N = 40, M = 20010;
int n, m, v[N], f[N][M];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j - v[i] >= 0 && f[i - 1][j - v[i]] + v[i] <= m)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i]);
        }
    cout << m - f[n][m];
}