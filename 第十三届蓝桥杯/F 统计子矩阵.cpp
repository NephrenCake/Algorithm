#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 500 + 10;

LL n, m, k;
LL A[N][N], ans;

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            A[i][j] = A[i][j] + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }  // 前缀和

    for (int w = 1; w <= n; w++)
        for (int h = 1; h <= m; h++)
            for (int x1 = 0; x1 <= n; x1++)
                for (int y1 = 0; y1 <= m; y1++) {
                    int x2 = x1 + w, y2 = y1 + h;
                    if (x2 > n || y2 > m)
                        continue;
                    LL sum = A[x2][y2] - A[x1][y2] - A[x2][y1] + A[x1][y1];
                    if (sum <= k)
                        ans++;
                }

    cout << ans << endl;
    return 0;
}
