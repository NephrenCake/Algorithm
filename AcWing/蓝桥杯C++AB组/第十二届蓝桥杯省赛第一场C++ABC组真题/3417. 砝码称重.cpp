#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3420/

/**
 * 状态表示 f[i][j]
 *      集合 所有只考虑前 i 个砝码，最终称得质量为 j 的方案的集合
 *      属性 bool是否可以
 * 状态计算
 *      不放砝码 | 放在左边 | 放在右边
 *      f[i - 1][j] | f[i - 1][j - w[i]] | f[i - 1][j + w[i]]
 *
 * 由于在过程中可以称出负数，因此需要保留负数精度，解决方法是增加一个偏移量
 */

const int N = 110, M = 2e5 + 10, B = M / 2;

int n, m, w[N];
bool f[N][M];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        m += w[i];
    }

    f[0][B] = true;
    for (int i = 1; i <= n; i++)
        for (int j = -m; j <= m; j++) {
            f[i][j + B] = f[i - 1][j + B];
            if (j - w[i] >= -m) f[i][j + B] |= f[i - 1][j - w[i] + B];
            if (j + w[i] <= m) f[i][j + B] |= f[i - 1][j + w[i] + B];
        }

    int ans = 0;
    for (int j = 1; j <= m; j++)
        ans += f[n][j + B];
    cout << ans;
}
