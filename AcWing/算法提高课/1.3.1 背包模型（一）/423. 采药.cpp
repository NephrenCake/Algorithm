#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 1010;
int n, m, w[N], v[N], f[N][M];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j - v[i] >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m];
}