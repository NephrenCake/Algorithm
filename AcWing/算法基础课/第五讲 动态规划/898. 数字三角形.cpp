#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int n, a[N][N], f[N][N];

int main() {
    cin >> n;

    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    int res = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[n][i]);
        // cout << f[n][i] << " ";
    }
    cout << res;
}
