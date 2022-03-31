#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1216/

/**
 * 分析（https://www.acwing.com/solution/content/9223/）
 *      1. 设第一个数为 x，则第二个数为 x + d1，第三个数为 x + d1 + d2 … 这里的 d1，d2 … 表示 +a 或者 -b，
 *      2. 所以这个数列为：x , x + d1, x + d1 + d2, x + d1 + d2 + d3, …, x + d1 + d2 + … + dn-1，
 *      3. 又因为数列之和为s，所以转化成：n * x + (n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + … + dn-1 = s
 *      4. 再在一步转化：{s - [(n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + … + dn-1]} / n = x
 *      5. 因为 x 一定是整数，所以又转化成：s 与 (n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + … + dn-1 模 n 的余数相同。
 *      到这里就转化成了组合问题，下面就可以用闫氏dp分析法了。
 *      6. 状态表示：f[i][j]
 *              集合 表示要选 i 个 a 或者 -b，且除 n 余数为 j 的所有集合的数量。
 *              目标 最后求得是f[n-1][s%n]的值
 *              属性 count
 *      7. 状态计算：
 *              最后一项是 +a 的所有方案 | 最后一项是 -b 的所有方案
 *              第 i 个选 a：(n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + … + 2 * dn-2 + a 模 n == j 模 n。
 *              则：(n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + … + 2 * dn-2 模 n == j - a 模 n。
 *              系数和下标之和为 n，所以第 i 项的的系数为 n - i。
 *              所以：f[i][j] = f[i - 1][j - (n - i) * a]
 *              第i个选b：同理：f[i][j] = f[i - 1][j + (n - i) * b]
 * todo 值得再做
 */

const int N = 1010, MOD = 100000007;

int f[N][N];

int get_mod(int a, int b) {
    // 求 a 除以 b 的正余数
    return (a % b + b) % b;
}

int main() {
    int n, s, a, b;  // 长度为 n, 和为 s, 增加 a, 或者减少 b
    cin >> n >> s >> a >> b;

    f[0][0] = 1;  // 选 0 个 a 或 -b，且余数为 0 的所有集合的数量是 1 个，同样选 0 个 a 或 -b，且余数不为 0 的所有集合的数量是 0 个。
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++) {
            // 两边状态子集，一个是选a，一个是选b。
            f[i][j] = (f[i - 1][get_mod(j - a * (n - i), n)] + f[i - 1][get_mod(j + b * (n - i), n)]) % MOD;
        }

    cout << f[n - 1][get_mod(s, n)];
}
