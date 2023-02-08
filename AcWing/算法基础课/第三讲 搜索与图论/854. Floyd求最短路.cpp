#include <iostream>

using namespace std;

const int N = 210;
int n, m, q, f[N][N];

int main() {
    cin >> n >> m >> q;
    int x, y, z;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) f[i][j] = 0;
            else f[i][j] = 0x3f3f3f3f;
    while (m--) {
        cin >> x >> y >> z;
        f[x][y] = min(f[x][y], z);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        cin >> x >> y;
        if (f[x][y] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
        else cout << f[x][y] << endl;
    }
}
