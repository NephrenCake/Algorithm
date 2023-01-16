#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n, m, s[N], v[N], w[N], f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= s[i] && j - k * v[i] >= 0; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            // f[i][j] = f[i - 1][j];  // k = 0
            // for (int k = 1; k <= s[i]; k++)
            //     if (j - k * v[i] >= 0)
            //         f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        }
    cout << f[n][m];
}
