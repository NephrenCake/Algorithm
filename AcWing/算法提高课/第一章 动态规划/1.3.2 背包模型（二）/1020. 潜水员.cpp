#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, P = 22, Q = 80;
int n, V1, V2, v1[N], v2[N], w[N], f[N][P][Q];

// 朴素法
int main() {
    cin >> V1 >> V2 >> n;  // 氧，氮,气缸的个数
    for (int i = 1; i <= n; i++)
        cin >> v1[i] >> v2[i] >> w[i];  // 氧和氮的容量及气缸重量

    memset(f, 0x3f, sizeof f);
    f[0][0][0] = 0;  // 状态表示：前0个物品，费用1不小于0，费用2不小于0的最低总价值

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= V1; j++)
            for (int k = 0; k <= V2; k++) {
                f[i][j][k] = f[i - 1][j][k];  // 不选第i个物品
                // 选第i个物品，f[0][0][0]表示了所有费用为负数和零的集合。氧气或者氮气所需的是数量是负数时，可以与数量0的状态等价
                // 如，f[1][1][1]可以从f[0][-1][-1]，即f[0][0][0]中转移过来。f[0][-1][-1]与f[0][0][0]都是0
                f[i][j][k] = min(f[i][j][k], f[i - 1][max(j - v1[i], 0)][max(k - v2[i], 0)] + w[i]);
            }
    cout << f[n][V1][V2];
}
