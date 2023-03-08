#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;
int n, m, a[N], f[N][M];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];  // 不选第i个数
            if (j - a[i] >= 0)  // 选第i个数
                f[i][j] += f[i - 1][j - a[i]];
        }
    }
    cout << f[n][m];
}
