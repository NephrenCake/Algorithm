#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.acwing.com/problem/content/3494/

/**
 * f[i, a, b, k]: 表示已经放好了前i - 1列，第i - 2列的状态是a, 第i - 1列的状态是b, 共放了 k 匹马的方案的集合
 * 假设第 i 列的状态是 c
 * a，b和c是二进制数： 比如说c=10010, 表示第i列的第0行和第3行上面放了一匹马
 *
 * 状态转移: f[i,b,c,k] += f[i - 1, a, b, k - t]
 */

const int N = 110, M = 1 << 6, K = 21, MOD = 1e9 + 7;

int n, m, k;  // 棋盘的行数、列数和马的个数
long long f[N][M][M][K];

int get_count(int x) {  // 计算当前列增加了多少个1
    int res = 0;
    for (; x; x -= (x & -x))res++;
    return res;
}

int main() {
    cin >> n >> m >> k;
    int max_n = 1 << n;
    f[0][0][0][0] = 1;  // 初始化
    for (int i = 1; i <= m; i++)
        for (int a = 0; a < max_n; a++)
            for (int b = 0; b < max_n; b++) {
                if ((a >> 2) & b || a & (b >> 2)) continue;  // 判断前前列和前列有没有发生冲突剪枝
                for (int c = 0; c < max_n; c++) {
                    if ((c >> 2) & b || c & (b >> 2)) continue;  // 判断前列和当前列有没有发生冲突
                    if ((c >> 1) & a || c & (a >> 1)) continue;  // 判断前前列和当前列有没有发生冲突
                    int t = get_count(c);
                    for (int j = t; j <= k; j++)  // 背包计算个数
                        f[i][b][c][j] = (f[i][b][c][j] + f[i - 1][a][b][j - t]) % MOD;
                }
            }
    int res = 0;
    for (int i = 0; i < max_n; i++)//对前前列和前列不同的状态最终有多少个可以摆放的方案数
        for (int j = 0; j < max_n; j++)
            res = (res + f[m][i][j][k]) % MOD;
    cout << res;
}
