#include <iostream>

using namespace std;

const int N = 10010;
int n, f[N][N], ans = -0x3f3f3f3f;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
            if (j == 1) f[i][j] += f[i - 1][j];
            else if (i == j) f[i][j] += f[i - 1][j - 1];
            else f[i][j] += max(f[i - 1][j], f[i - 1][j - 1]);
            if (i == n) ans = max(ans, f[i][j]);
        }
    cout << ans;
}
