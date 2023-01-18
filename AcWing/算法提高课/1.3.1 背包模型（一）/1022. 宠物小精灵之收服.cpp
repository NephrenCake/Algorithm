#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 510, K = 110;
int V1, V2, n, f[N][M], v1[K], v2[K];

int main() {
    cin >> V1 >> V2 >> n;  // 精灵球数量，体力。
    for (int i = 1; i <= n; i++)
        cin >> v1[i] >> v2[i];  // 精灵球的数量，体力。

    for (int i = 1; i <= n; i++)  // n个精灵中的前i个精灵
        for (int j = V1; j - v1[i] >= 0; j--)  // V1个精灵球用前j个
            for (int k = V2 - 1; k - v2[i] >= 0; k--) {  // V2的体力用前k个
                // 注意体力不能全部用完，从V2 - 1开始
                f[j][k] = max(f[j][k], f[j - v1[i]][k - v2[i]] + 1);
            }
    cout << f[V1][V2 - 1];

    for (int i = 0; i < V2; i++)
        if (f[V1][i] == f[V1][V2 - 1]) {
            cout << " " << V2 - i;
            return 0;
        }
}

// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 1010, M = 510, K = 110;
// int V1, V2, n, f[K][N][M], v1[K], v2[K];
//
// // Memory Limit Exceeded
// int main() {
//     cin >> V1 >> V2 >> n;  // 精灵球数量，体力。
//     for (int  i = 1; i <= n; i++) cin >> v1[i] >> v2[i];  // 精灵球的数量，体力。
//
//     for (int i = 1; i <= n; i++)  // n个精灵中的前i个精灵
//         for (int j = 1; j <= V1; j++)  // V1个精灵球用前j个
//             for (int k = 1; k < V2; k++) {  // V2的体力用前k个
//                 f[i][j][k] = f[i - 1][j][k];
//                 if (j - v1[i] >= 0 && k - v2[i] >= 0)
//                     f[i][j][k] = max(f[i][j][k], f[i - 1][j - v1[i]][k - v2[i]] + 1);
//             }
//     cout << f[n][V1][V2 - 1];
//
//     for (int i = 0; i < V2; i++)
//         if (f[n][V1][i] == f[n][V1][V2 - 1]) {
//             cout << " " << V2 - i;
//             return 0;
//         }
// }
