#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/897/

/**
 * 状态表示 f[i]
 *      集合 所有以i结尾的严格单调上升子序列的集合
 *      属性 max
 * 状态计算
 *      由“所有以i-1结尾的严格单调上升子序列的集合”转移到“所有以i结尾的严格单调上升子序列的集合”
 *      结尾前的一个数可能为 0 | 1 | ... | i - 1
 * 转移方程
 *      max(ans, f[i - 1] + 1)
 *
 */

const int N = 1010;

int n, res;
int f[N], a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = 1;  // 必定会有一个解
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])  // 只有当第i个数大于第j个数时，才能包含“以第j个数结尾的严格单调上升子序列的集合”的状态。即遍历可能的上一状态的子集合
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res;
}
