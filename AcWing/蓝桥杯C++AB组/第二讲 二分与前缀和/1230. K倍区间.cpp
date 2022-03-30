#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1232/

/**
 * 1. 先考虑暴力
 *      for r: 1~n
 *          for l: 1~r
 *              if s[r] - s[l - 1] % k == 0:
 *                  res++
 * 2. 翻译：当r固定时，l 在 1~r 之间找到有多少l满足：(s[r] - s[l - 1]) % k == 0
 * 3. 等价变形：当r固定时，l 在 0~r-1 之间找到有多少l满足：(s[r] - s[l]) % k == 0
 *    即：有多少个 s[r] 与 s[l] 的模k余数相同
 *
 *       5 2
 * 原数组 1 2 3 4 5
 * 前缀和 1 3 6 10 15
 * 取模后 1 1 0 0 1
 */

typedef long long LL;

const int N = 100010;

int n, k;
LL s[N], cnt[N];  // 前缀和数组 取模结果数量统计（当map用）

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = (s[i] + s[i - 1]) % k;  // 前缀和仅需保留取模结果
    }

    LL res = 0;
    // cnt[0] = 1;
    for (int r = 1; r <= n; r++) {
        // 扫一遍数组，其实是遍历每个r的取值
        res += cnt[s[r]];  // 加上"当r固定时"具有相同余数的数量
        cnt[s[r]]++;  // 为统计的余数++
    }
    // 实际上，前一部分只是计算了长度大于1的区间组合，还差单个数的情况没有统计，即本身取模结果就为0
    cout << res + cnt[0];  // 与前一句 `cnt[0] = 1;` 是等价的
}
