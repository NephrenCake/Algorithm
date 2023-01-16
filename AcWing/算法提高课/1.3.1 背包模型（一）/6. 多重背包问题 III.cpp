#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 20010;
int n, m, s[N], v[N], w[N], f[N][M], q[M];
// q为单调队列，存的是窗口内最大值的下标
// q单调递减，可以维护最大值，窗口内最大值的下标为队头元素，窗口内最大值为q[hh]

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++) {  // 遍历物品，前i个物品
        // 循环O(M)
        for (int r = 0; r < v[i]; r++) {  // 遍历余数
            int hh = 0, tt = -1;
            for (int j = r; j <= m; j += v[i]) {  // 遍历空间，前j的空间
                while (hh <= tt && j - q[hh] > s[i] * v[i]) hh++;
                //     hh <= tt 队列不空
                //                 j - q[hh] 是计划用于装第i个物品的空间
                //                         超出 s[i] * v[i] 即s个第i个物品的理论空间
                while (hh <= tt && f[i - 1][q[tt]] + (j - q[tt]) / v[i] * w[i] <= f[i - 1][j]) --tt;
                //     hh <= tt 队列不空
                //                               装了 (j - q[tt]) / v[i] 个物品
                //                             价值为 (j - q[tt]) / v[i] * w[i]
                q[++tt] = j;
                f[i][j] = f[i - 1][q[hh]] + (j - q[hh]) / v[i] * w[i];
            }
        }
    }
    cout << f[n][m];
}
