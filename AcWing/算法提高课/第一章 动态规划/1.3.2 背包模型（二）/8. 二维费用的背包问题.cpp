#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 110;
int n, V1, V2, f[M][M];

int main() {
    cin >> n >> V1 >> V2;  // 物品件数、背包容积和背包可承受的最大重量

    for (int i = 1; i <= n; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;  // 体积、重量和价值
        for (int j = V1; j - v1 >= 0; j--)
            for (int k = V2; k - v2 >= 0; k--)
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + w);
    }
    cout << f[V1][V2];
}
// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 1010, M = 110;
// int n, V1, V2, w[N], v1[N], v2[N], f[N][M][M];
//
// int main() {
//     cin >> n >> V1 >> V2;  // 物品件数、背包容积和背包可承受的最大重量
//     for (int i = 1; i <= n; i++)
//         cin >> v1[i] >> v2[i] >> w[i];  // 体积、重量和价值
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= V1; j++)
//             for (int k = 1; k <= V2; k++) {
//                 f[i][j][k] = f[i - 1][j][k];
//                 if (j - v1[i] >= 0 && k - v2[i] >= 0)
//                     f[i][j][k] = max(f[i][j][k], f[i - 1][j - v1[i]][k - v2[i]] + w[i]);
//             }
//     cout << f[n][V1][V2];
// }
