#include <iostream>
#include <cstring>

using namespace std;

const int N = 30, M = 110;
int n, m, a[N], f[N][M];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (j == 0) f[i][j] = 0;
            else {
                f[i][j] = f[i - 1][j];
                if (j - a[i] >= 0)
                    f[i][j] = min(f[i][j], f[i - 1][j - a[i]] + 1);
                // cout << a[i] << " " << j << " " << f[i][j] << endl;
            }
    if (f[n][m] == 0x3f3f3f3f) cout << 0;
    else cout << f[n][m];
}
