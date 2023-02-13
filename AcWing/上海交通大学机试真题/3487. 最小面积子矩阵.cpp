#include <iostream>

using namespace std;

const int N = 110;
int n, m, k, a[N][N], ans = 0x3f3f3f3f;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j] += a[i - 1][j];  // 列方向作前缀和

    for (int y1 = 1; y1 <= n; y1++)
        for (int y2 = y1; y2 <= n; y2++) {
            int sum = a[y2][1] - a[y1 - 1][1];
            for (int x1 = 1, x2 = 1; x1 <= m && x2 <= m; ) {
                while (sum < k && x2 <= m) x2++, sum += a[y2][x2] - a[y1 - 1][x2];
                if (x2 <= m)
                    ans = min(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
                sum -= a[y2][x1] - a[y1 - 1][x1], x1++;
            }
        }
    if (ans == 0x3f3f3f3f) cout << -1;
    else cout << ans;
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 110;
// int a[N][N], n, m, k, ans = 0x3f3f3f3f;
//
// // 暴力二维前缀和
// int main() {
//     cin >> n >> m >> k;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> a[i][j], a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
//
//     if (a[n][m] < k) {
//         cout << -1;
//         return 0;
//     }
//     for (int x1 = 1; x1 <= n; x1++)
//         for (int y1 = 1; y1 <= m; y1++)
//             for (int x2 = x1; x2 <= n; x2++)
//                 for (int y2 = y1; y2 <= m; y2++)
//                     if (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] >= k)
//                         ans = min(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
//     cout << ans;
// }
