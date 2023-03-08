#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, a[N], f[N], g[N];

int main() {
    while (cin >> a[n]) n++;  // 未确定n时的输入

    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)  // 严格单调上升和非严格单调下降是相对的，都从前往后遍历
            if (a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        while (k < cnt && g[k] < a[i]) k++;
        g[k] = a[i];
        cnt = max(cnt, k + 1);
    }
    cout << cnt;
    return 0;
}
