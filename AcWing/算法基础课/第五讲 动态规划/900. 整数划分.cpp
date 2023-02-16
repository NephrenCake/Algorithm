#include <iostream>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int n, f[N][N];

int main() {
    cin >> n;

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++) {  // j´Ó0¿ªÊ¼
            f[i][j] = f[i - 1][j];
            if (j - i >= 0)
                f[i][j] = (f[i][j] + f[i][j - i]) % MOD;
        }
    cout << f[n][n];
}
