#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3/

// 01 背包：f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i])
// 完全背包：f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];


// 解2：优化
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            // f[i][j] = f[i - 1][j];  // 1. 先算右边，后算左边；因此右边是上一层的记录，复制到新一层的记录，等价；
            // f[j] = f[j];  // 2. 本身与不写等价
            if (v[i] <= j) {
                // f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);  // 1. 本身都是在同一个维度操作，去掉第一维依然等价
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }

    cout << f[m];  // 根据定义输出结果
}

// const int N = 1010;
// int n, m;
// int v[N], w[N];
// int f[N][N];
//
//
// 解1：朴素
// int main(){
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i) {
//         cin >> v[i] >> w[i];
//     }
//
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];
//             if (v[i] <= j)
//                 f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//
//     cout << f[n][m];
// }