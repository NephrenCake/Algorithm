#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;
int n, m, a[N][N], f[N][N], res[N];

int main() {
    cin >> n >> m;  /// 分公司数,设备台数
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= m; k++)
            cin >> a[i][k];

    for (int i = 1; i <= n; i++)  // 前i个分公司
        for (int j = 1; j <= m; j++) {  // 前j个设备
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j; k++)  // 分k个设备
                f[i][j] = max(f[i][j], f[i - 1][j - k] + a[i][k]);
        }
    cout << f[n][m] << endl;

    int t = m;
    for (int i = n; i; i--)  // 前i个分公司
        for (int k = t; k; k--)  // 分k个设备
            if (t - k >= 0 && f[i][t] == f[i - 1][t - k] + a[i][k]) {
                t -= k;
                res[i] = k;
                break;
            }
    for (int i = 1; i <= n; i++)
        cout << i << " " << res[i] << endl;
}
