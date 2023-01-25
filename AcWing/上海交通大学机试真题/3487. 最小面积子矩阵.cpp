#include<iostream>

using namespace std;

const int N = 110;
int n, m, k, a[N][N], res = 0x3f3f3f3f;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j];  // 对每一列构造一维前缀和
        }

    for (int i = 1; i <= n; i++)  // 枚举行区间
        for (int j = 0; j < i; j++)
            for (int l = 0, r = 1, sum = 0; r <= m; r++) {  // 枚举列区间，双指针
                sum += a[i][r] - a[j][r];  // 快指针走一步
                while (sum - (a[i][l + 1] - a[j][l + 1]) >= k) {
                    sum -= (a[i][l + 1] - a[j][l + 1]);
                    l++;  // 慢指针走到临界处
                }
                if (sum >= k)
                    res = min(res, (i - j) * (r - l));
            }

    if (res == 0x3f3f3f3f) cout << -1;
    else cout << res;
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 110;
// int n, m, k, a[N][N], ans = 0x3f3f3f3f;
//
// // 暴力二维前缀和
// int main() {
//     cin >> n >> m >> k;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++){
//             cin >> a[i][j];
//             a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
//
//             for (int x = 0; x < i; x++)
//                 for (int y = 0; y < j; y++)
//                     if (a[i][j] - a[i][y] - a[x][j] + a[x][y] >= k)
//                         ans = min(ans, (i - x) * (j - y));
//         }
//
//     if (ans == 0x3f3f3f3f) cout << -1;
//     else cout << ans;
// }
