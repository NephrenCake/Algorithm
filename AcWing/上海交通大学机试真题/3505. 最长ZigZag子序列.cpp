#include <iostream>

using namespace std;

const int N = 60;
int n, a[N], f[N][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // f[i][j] 前i个数且以a[i]结尾，最后一个数为下降/上升，的最长 ZigZag 子序列的长度
    // 不选 | 选且上升 | 选且下降
    f[1][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = f[i - 1][0];
        f[i][1] = f[i - 1][0];  // 不选
        for (int k = 1; k < i; k++) {
            if (a[i] > a[k])  // 可以选上升
                f[i][1] = max(f[i][1], f[k][0] + 1);
            else if (a[i] < a[k])
                f[i][0] = max(f[i][0], f[k][1] + 1);
        }
    }
    cout << max(f[n][0], f[n][1]);
}
