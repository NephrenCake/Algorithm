#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/1224/

/**
 * 状态表示 f[i][j]
 *      集合 所有 l 到 r 之间的回文子序列的集合
 *      属性 len 的 max
 * 状态计算
 *      lr都在 | 只有l | 只有r | lr都没
 *      f[i][j] = max(f[l - 1][r - 1] + 2, max(f[l][r - 1], f[l + 1][r]))
 */

const int N = 1010;

string s;
int f[N][N];

int main() {
    cin >> s;
    int n = s.size();

    for (int len = 1; len <= n; len++)
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = 1;
            } else {
                if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1] + 2;
                f[l][r] = max(f[l][r], f[l][r - 1]);
                f[l][r] = max(f[l][r], f[l + 1][r]);
            }
        }
    cout << n - f[0][n - 1];
}
