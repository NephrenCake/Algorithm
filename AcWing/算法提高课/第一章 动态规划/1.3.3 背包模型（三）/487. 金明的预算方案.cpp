#include <iostream>
#include <vector>

using namespace std;

#define v first
#define w second
typedef pair<int, int> PII;

const int N = 70, M = 32010;
int n, m, f[M];
PII fa[N];
vector<PII> son[N];

// 2. 一维优化
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!c) fa[i] = {a, b * a};
        else son[c].push_back({a, b * a});
    }

    for (int i = 1; i <= n; i++)  // 前i个物品组。每个物品都有可能是一个组，最多n个物品组，实际是多少个主件
        for (int j = m; j >= 0; j--)  // 前j的空间
            if (fa[i].v)  // 可有可无，因为一维dp状态自动转移到下一层
                for (int k = 0; k < 1 << son[i].size(); k++) {  // 二进制枚举，每位1表示选这个物品0表示不选，k表示第几种策略
                    // 计算该策略占用v空间，得到w价值
                    int v = fa[i].v, w = fa[i].w;
                    for (int l = 0; l < son[i].size(); l++)
                        if (k >> l & 1) {
                            v += son[i][l].v;
                            w += son[i][l].w;
                        }
                    if (j - v >= 0)  // 转移方程
                        f[j] = max(f[j], f[j - v] + w);
                }
    cout << f[m] << endl;
}

// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// #define v first
// #define w second
// typedef pair<int, int> PII;
//
// const int N = 70, M = 32010;
// int n, m, f[N][M];
// PII fa[N];  // 物品i为主件时，存在fa[i]
// vector<PII> son[N];  // 物品j为物品i的附件时，存在son[i]
//
// // 1. 朴素二维 二进制枚举
// int main() {
//     cin >> m >> n;
//     for (int i = 1; i <= n; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;  // 价格 重要度 主件还是附件
//         if (!c) fa[i] = {a, a * b};
//         else son[c].push_back({a, a * b});
//     }
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++) {
//             // 当主件i不是主件时，当做一个0价格0价值的物品来保持状态f的转移
//             f[i][j] = f[i - 1][j];
//             if (fa[i].v)  // 可有可无
//                 for (int k = 0; k < 1 << son[i].size(); k++) {
//                     int v = fa[i].v, w = fa[i].w;
//                     for (int l = 0; l < son[i].size(); l++)
//                         if (k >> l & 1) {
//                             v += son[i][l].v;
//                             w += son[i][l].w;
//                         }
//                     if (j - v >= 0)
//                         f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
//                 }
//         }
//     cout << f[n][m];
// }
