#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1214/

/**
 * 状态表示 f[i][j][k][c]
 *      集合 所有从起点走到[i, j]，且已经恰好取了k件物品，且最后一件物品的价值为c的合法方案
 *      属性 count
 * 状态计算
 *      建议画图
 * 转移方程
 *      把上一状态所有的子集相加
 */

const int N = 60, MOD = 1000000007;

int n, m, k;
int w[N][N];
int f[N][N][13][14];  // 1≤k≤12,0≤Ci≤12
int ans;

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
            w[i][j]++;  // 从0~12偏移到1~13
        }

    // 初始化第一个格子的选择
    f[1][1][1][w[1][1]] = 1;  // 在起点[1, 1]，且已经取了1件物品，且这件物品的价值为w[1][1]的合法方案
    f[1][1][0][0] = 1;  // 在起点[1, 1]，且不取物品，且价值为0的合法方案
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                continue;  // 已经处理过了
            for (int u = 0; u <= k; u++)
                for (int v = 0; v <= 13; v++) {
                    // 1. 不拿的子集
                    int& ways = f[i][j][u][v];  // 先拿出来，减少代码量
                    ways = (ways + f[i - 1][j][u][v]) % MOD;
                    ways = (ways + f[i][j - 1][u][v]) % MOD;  // 两个相加不会爆int，但三个会
                    // 2. 拿的子集
                    if (u > 0 && v == w[i][j]) {
                        // u表示的是当前已经拿取了多少个宝物。如果不加u>0的话，会越界。因为不可能从-1个宝物转移到0个宝物。
                        // 当前正在枚举拿完之后为最大价值为v的情况，又最后一个拿的物品必为最大价值，因此当前位置的价值必须等于v。
                        for (int c = 0; c < v; c++) {
                            // 当可以拿当前物品，即上一状态的最大价值比当前物品价值小时，所有上一状态的方案都被吸收
                            ways = (ways + f[i - 1][j][u - 1][c]) % MOD;
                            ways = (ways + f[i][j - 1][u - 1][c]) % MOD;
                        }
                    }
                }
        }

    ans = 0;
    for (int i = 0; i <= 13; i++)
        ans = (ans + f[n][m][k][i]) % MOD;
    cout << ans;
}
