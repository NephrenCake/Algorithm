#include <iostream>

using namespace std;

const int N = 310;
int n, a[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];

    // f[l][r] 区间[l, r]合并所需最小代价
    for (int l = 2; l <= n; l++)
        for (int i = 1, j; i + l - 1 <= n; i++) {
            j = i + l - 1;
            f[i][j] = 0x3f3f3f3f;
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            // printf("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    cout << f[1][n];
}
