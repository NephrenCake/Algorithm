#include <iostream>

using namespace std;

const int N = 510;
int n, f[N][N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> f[i][j];

    // f[k][i][j] 以k~n节点为中间节点，i到j的最短距离
    for (int k = n; k >= 2; k--) {
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                f[j][i] = f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                if (i >= k && j >= k) {
                    // printf("k:%d f[%d][%d]\n", k, i, j);
                    ans += 2 * f[i][j];
                }
            }
    }
    cout << ans;
}
