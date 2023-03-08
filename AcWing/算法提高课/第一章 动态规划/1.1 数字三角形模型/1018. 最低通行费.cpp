#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n, f[N][N], a[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i == 1 && j == 1)
                f[i][j] = a[i][j];
            else if (i == 1)
                f[i][j] = f[i][j - 1] + a[i][j];
            else if (j == 1)
                f[i][j] = f[i - 1][j] + a[i][j];
            else
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    cout << f[n][n];
}