#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 6010;
int n, m, v[N], w[N], s[N], f[N][M], q[M];

// 2. 单调队列
int main() {
    cin >> n >> m;  // 奖品的种数，拨款金额
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];  // 价格、价值、最大数量

    for (int i = 1; i <= n; i++) {
        for (int r = 0; r < v[i]; r++) {
            int hh = 0, tt = -1;
            for (int j = r; j <= m; j += v[i]) {
                while (hh <= tt && q[hh] < j - s[i] * v[i]) hh++;
                while (hh <= tt && f[i - 1][q[tt]] + (j - q[tt]) / v[i] * w[i] <= f[i - 1][j]) tt--;
                q[++tt] = j;
                f[i][j] = f[i - 1][q[hh]] + (j - q[hh]) / v[i] * w[i];
            }
        }
    }
    cout << f[n][m];
}

// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 510, M = 6010;
// int n, m, v[N], w[N], s[N], f[N][M];
//
// 1. 朴素
// int main() {
//     cin >> n >> m;  // 奖品的种数，拨款金额
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i] >> s[i];  // 价格、价值、最大数量
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             for (int k = 0; k <= s[i]; k++)
//                 if (j - k * v[i] >= 0)
//                     f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
//     cout << f[n][m];
// }
