#include <iostream>

using namespace std;

const int N = 110;
int n, m, c[N], v[N][N], w[N][N], f[N];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        for (int j = 1; j <= c[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j; j--)
            for (int k = 1; k <= c[i]; k++)
                if (j - v[i][k] >= 0)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    cout << f[m];
}
