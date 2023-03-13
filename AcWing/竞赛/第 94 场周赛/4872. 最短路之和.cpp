#include <iostream>

using namespace std;

const int N = 510;
long long n, f[N][N], q[N], ans[N], used[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> f[i][j];
    for (int i = 1; i <= n; i++)
        cin >> q[i];

    for (int l = n; l >= 1; l--) {
        used[q[l]] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][q[l]] + f[q[l]][j]);
                if (used[i] && used[j])
                    ans[l] += f[i][j];
            }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
