#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, K = 110;
int n, k, a[N], f[N][K][2], ans;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // f[i][j][l] 前i天中，且正在进行第j次交易，且第i天持有/不持有股票
    for (int j = 1; j <= k; j++) f[0][j][1] = -0x3f3f3f3f;  // 将不合法的状态排除
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + a[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - a[i]);
        }
    for (int i = 0; i <= k; i++) ans = max(ans, f[n][i][0]);
    cout << ans;
}
