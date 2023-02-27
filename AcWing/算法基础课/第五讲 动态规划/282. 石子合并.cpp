#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;
int n, a[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
        }
    cout << f[1][n];
}
