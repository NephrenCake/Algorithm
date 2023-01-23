#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n, m, c[N], v[N][N], w[N][N], f[N][N];


int main() {
    cin >> n >> m;  // 物品组数，背包容量
    for (int i = 1; i <= n; i++) {  // 物品组数
        cin >> c[i];  // 每组个数
        for (int j = 1; j <= c[i]; j++)  // 体积和价值
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++) {  // 前i个物品/组
        for (int j = 1; j <= m; j++) {  // 前j个空间
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= c[i]; k++)
                if (j - v[i][k] >= 0)
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    cout << f[n][m];
}
