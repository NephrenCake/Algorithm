#include <iostream>
#include <cstring>

using namespace std;

const int N = 210;
int n, m, q, a, b, c, x, y, f[N][N];

int main() {
    cin >> n >> m >> q;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    while (m-- && cin >> a >> b >> c) f[a][b] = min(f[a][b], c);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    while (q-- && cin >> x >> y)
        if (f[x][y] > 0x3f3f3f3f / 2) cout << "impossible"  << endl;
        else cout << f[x][y] << endl;
}
