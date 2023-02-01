#include <iostream>

using namespace std;

const int N = 310;
int n, a[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int l = 1; l < n; l++)
        for (int i = 1; i + l <= n; i++) {
            int j = i + l;
            f[i][j] = 2e8;
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
        }
    cout << f[1][n];
}
