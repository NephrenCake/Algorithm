#include <iostream>

using namespace std;

const int N = 110;
int n, a[N * 2], f[N * 2][N * 2], ans;

int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++) cin >> t, a[i] = a[i + n] = t;

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
            if (len == n)
                ans = max(ans, f[i][j]);
        }
    cout << ans;
}
