#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/2/

// 解2：优化空间
const int N = 1010;
int n, m;  // 物品数量和背包容积
int v[N], w[N];
int f[N];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j) {
            if (j >= v[i]) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);  // 考虑右半边的子集更新状态
                // f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
                // 注意原式的 f[i - 1][j - v[i]] 取的是 [i - 1] 状态下的信息，若 j 在循环中升序，则信息已经被改变
            }
        }
    }

    cout << f[m] << endl;
}

// 解1：暴力dp
// const int N = 1010;
// int n, m;  // 物品数量和背包容积
// int v[N], w[N];
// int f[N][N];
//
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i) {
//         cin >> v[i] >> w[i];
//     }
//
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];  // 左半边的子集
//             if (j >= v[i]) {
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);  // 考虑右半边的子集更新状态
//             }
//         }
//     }
//
//     cout << f[n][m] << endl;
// }
