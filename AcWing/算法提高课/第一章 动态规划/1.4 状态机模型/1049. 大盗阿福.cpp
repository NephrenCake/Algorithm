#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int t, n, a[N], f[N][2];

int main() {
    cin >> t;
    while (t-- && cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];

        // f[i][j] 抢前i家，且最后一家抢/不抢
        // 抢 f[i - 1][0] + a[i]  |  不抢 max(f[i - 1][0], f[i - 1][1])
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + a[i];
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
}
