#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, a[N], sum[N];
int dis = 0x3f3f3f3f, ans;  // 两数组和的距离 较小的那个数组和
bool flag;

void dfs(int cur, int idx) {
    if (flag) return;
    if (cur > sum[n - 1] / 2) return;  // 只寻找较小的数组和，另外一个一定能表示为sum[n - 1] - cur
    if (idx == -1) {
        int d = sum[n - 1] - 2 * cur;
        if (d < dis) {
            dis = d;
            ans = cur;
            if (dis == 0 || dis == 1)  // 如果已经找到不可能再优化的结果，直接返回
                flag = true;
        }
        return;
    }

    dfs(cur + a[idx], idx - 1);
    // 当接下来全选时，则选上的数组元素之和为cur + sum[idx - 1]。如果全选都导致dis越来越大，那就不用遍历了
    int next_max = cur + sum[idx - 1];
    if (!(next_max < sum[n - 1] / 2 && sum[n - 1] - 2 * (next_max) > dis))
        dfs(cur, idx - 1);
    // else
    //     cout << "next_max " << next_max << " " << sum[n - 1] / 2 << endl;
}

int main() {
    int t;
    while (cin >> t) a[n++] = t;

    sort(a, a + n);  // 从小到大排序可以将时间从515ms降到17ms
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = a[i] + sum[i - 1];  // 前缀和

    dfs(0, n - 1);  // 从后向前遍历每个元素，方便使用前缀和预判剪枝
    cout << sum[n - 1] - ans << " " << ans;
}
