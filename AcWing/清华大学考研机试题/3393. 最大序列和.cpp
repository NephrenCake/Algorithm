#include <iostream>

using namespace std;

const int N = 1e6 + 10;
long long n, a[N], f[N], ans = -0x3f3f3f3f;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // f[i] 前i个数以a[i]结尾的最大非空连续子序列和
    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        if (i > 1)
            f[i] = max(f[i], f[i - 1] + a[i]);
        ans = max(ans, f[i]);
    }
    cout << ans;
}
