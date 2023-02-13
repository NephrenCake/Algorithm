#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], s[N], n, ans, dis = 0x3f3f3f3f, flag;

void dfs(int idx, int cur) {
    if (cur > s[n - 1] / 2) return;  // 只寻找较小的数组和，另外一个一定能表示为sum[n - 1] - cur
    if (s[n - 1] - 2 * cur < dis)
        ans = cur, dis = s[n - 1] - 2 * cur;
    if (dis == 0 || dis == 1)  // 如果已经找到不可能再优化的结果，直接返回
        flag = 1;
    if (flag) return;
    if (idx == -1) return;  // 到达边界时必须返回，找到结果时也可以提前返回，不需要一定走到边界

    dfs(idx - 1, cur + a[idx]);
    // 当接下来全选时，则选上的数组元素之和为cur + sum[idx - 1]。如果全选都不及最大的ans，那就说明距离，那就不用遍历了
    if (s[idx - 1] + cur  >= ans)
        dfs(idx - 1, cur);
}

int main() {
    int t;
    while (cin >> t) a[n++] = t;

    sort(a, a + n);
    s[0] = a[0];
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];

    dfs(n - 1, 0);
    cout << s[n - 1] - ans << " " << ans;
}
