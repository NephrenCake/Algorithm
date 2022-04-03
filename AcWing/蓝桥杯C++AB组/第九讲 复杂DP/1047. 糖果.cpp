#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1049/

/**
 * 状态表示 f[i][j]
 *      集合 所有从前 i 件产品中选，且糖果总数除以 k 的余数为 j 的所有方案
 *      属性 max
 * 状态计算
 *      所有从前 i - 1 件产品中选，且糖果总数为 j * k 的选法的集合（不选第 i 件产品） | （选第 i 件产品）
 *      f[i][j] = max(f[i - 1][j] + f[i - 1][(j - w[i]) % k])
 */

const int N = 110;

int n, k;  // N 件产品,总数是 K 的整数倍
int w;
int f[N][N];

int main() {
    scanf("%d%d", &n, &k);
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w);
        for (int j = 0; j < k; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][(j + k - w % k) % k] + w);
    }
    printf("%d", f[n][0]);
}
