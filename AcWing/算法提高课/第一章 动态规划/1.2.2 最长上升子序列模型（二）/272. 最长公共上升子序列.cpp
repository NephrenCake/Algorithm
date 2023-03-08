#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;
int n, f[N][N];  // 由a序列前i个数、b序列前j个数，并且以b[j]结尾的最长公共上升子序列的长度
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++) {
    //         f[i][j] = f[i - 1][j];
    //         if (a[i] == b[j]) {
    //             f[i][j] = max(1, f[i][j]);
    //             for (int k = 1; k < j; k++)
    //                 if (b[j] > b[k])
    //                     f[i][j] = max(f[i][j], f[i - 1][k] + 1);
    //         }
    //     }
    for (int i = 1; i <= n; i++) {
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j])
                maxv = max(maxv, f[i - 1][j] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}
