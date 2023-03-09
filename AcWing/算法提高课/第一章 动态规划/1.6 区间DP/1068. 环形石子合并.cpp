#include <iostream>

using namespace std;

const int N = 210;
int n, a[N * 2], f[N * 2][N * 2], g[N * 2][N * 2], ans_min = 0x3f3f3f3f, ans_max;

int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++) cin >> t, a[i] = a[i + n] = t;
    for (int i = 1; i <= n * 2; i++) a[i] += a[i - 1];

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            g[i][j] = 0x3f3f3f3f;
            for (int k = i; k < j; k++)
                g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j] + a[j] - a[i - 1]);
            if (len == n)
                ans_min = min(ans_min, g[i][j]);
        }
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            if (len == n)
                ans_max = max(ans_max, f[i][j]);
        }
    cout << ans_min << endl << ans_max << endl;
}
