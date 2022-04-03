#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1052/

/**
 * 制造影分身时有多少种不同的分配方法
 * 状态表示 f[i][j]
 *      集合 所有能量为 i，分身个数为 j 的分配方法集合
 *      属性 count
 * 状态计算
 *      最小值为 0 | 最小值不为 0
 *      f[i][j] = f[i][j - 1] + f[i - j][j];
 */

const int N = 15;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;  // 查克拉能量为 M，影分身的个数最多为 N，
        int f[N][N] = {0};

        f[0][0] = 1;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i][j - 1];
                if (i >= j)
                    f[i][j] += f[i - j][j];
            }
        cout << f[m][n] << endl;
    }
}
