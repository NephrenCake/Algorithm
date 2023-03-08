#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m, v[N], w[N], f[N];

// 2. 空间优化
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (j - v[i] >= 0)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    cout << f[m];
}


// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 1010;
// int n, m, v[N], w[N], f[N][N];
//
// 2. 朴素
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i];
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++) {
//             f[i][j] = f[i - 1][j];
//             if (j - v[i] >= 0)
//                 f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//         }
//     cout << f[n][m];
// }

// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 1010;
// int n, m, v[N], w[N], f[N][N];
//
// 1. 暴力超时
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i];
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++) {
//             f[i][j] = f[i - 1][j];
//             for (int k = 1; j - k * v[i] >= 0; k++)
//                 f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);
//         }
//     cout << f[n][m];
// }
