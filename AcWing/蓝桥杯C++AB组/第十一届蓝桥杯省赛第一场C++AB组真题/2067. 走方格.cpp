#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/2069/

/**
 *   1 2 3 4 5 6 7 8
 * 1 a
 * 2   x   x   x   x
 * 3       o
 * 4   x   x   x   x
 * 5
 * 6   x   x   x   x
 * 7           o
 * 8   x   x   x   x
 *
 * 状态表示 f[i][j]
 *      集合
 *      属性 count
 */

const int N = 40;

int f[N][N];
int n, m;

int cal() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                f[1][1] = 1;
            else if (i % 2 == 0 && j % 2 == 0)
                continue;
            else {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
                // cout << i << " " << j << " " << f[i][j] << endl;
            }
        }
    return f[n][m];
}

int main() {
    cin >> n >> m;
    if (n % 2 == 0 && m % 2 == 0) {
        cout << 0;
        return 0;
    }
    cout << cal();
}
