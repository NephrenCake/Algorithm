#include <iostream>

using namespace std;

const int N = 1010, M = 1010;
int n, m, v, w, f[M];

int main() {
    cin >> n >> m;
    // f[i][j] 从前i个物品中选，不超过体积j，的最大价值
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = m; j; j--)
            if (j - v >= 0)
                f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m];
}
