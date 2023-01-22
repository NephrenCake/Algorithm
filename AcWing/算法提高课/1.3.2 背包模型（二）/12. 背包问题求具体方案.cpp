#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m, f[N][N], v[N], w[N], p[N][N];

int main() {
    cin >> n >> m;  // 物品数量和背包容积
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];  // 体积和价值

    for (int i = n; i; i--)  // 注意！dp从后向前遍历每个物品，方便字典序最小反推
        for (int j = 1; j <= m; j++)
            f[i][j] = j - v[i] >= 0 ? max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]) : f[i + 1][j];

    int t = m;
    for (int i = 1; i <= n; i++) {
        if (t >= v[i] && f[i][t] == f[i + 1][t - v[i]] + w[i]) {
            cout << i << " ";
            t -= v[i];
        }
    }
}
