#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int r, c, t, f[N][N], a[N][N];

int main() {
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
                f[i][j] = 0;
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }
        cout << f[r][c] << endl;
    }
}