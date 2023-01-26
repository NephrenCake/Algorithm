#include <iostream>

using namespace std;

const int N = 10010;
int n, a[N], f[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {  // 以a[i]结尾的最长连续递增的子序列
        f[i] = 1;
        if (a[i - 1] < a[i])
            f[i] = f[i - 1] + 1;
        ans = max(ans, f[i]);
    }
    cout << ans;
}
