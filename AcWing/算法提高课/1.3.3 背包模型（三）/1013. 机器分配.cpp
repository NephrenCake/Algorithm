#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;
int n, m, a[N][N], f[N][N], res[N];

int main() {
    cin >> n >> m;  /// �ֹ�˾��,�豸̨��
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= m; k++)
            cin >> a[i][k];

    for (int i = 1; i <= n; i++)  // ǰi���ֹ�˾
        for (int j = 1; j <= m; j++) {  // ǰj���豸
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j; k++)  // ��k���豸
                f[i][j] = max(f[i][j], f[i - 1][j - k] + a[i][k]);
        }
    cout << f[n][m] << endl;

    int t = m;
    for (int i = n; i; i--)  // ǰi���ֹ�˾
        for (int k = t; k; k--)  // ��k���豸
            if (t - k >= 0 && f[i][t] == f[i - 1][t - k] + a[i][k]) {
                t -= k;
                res[i] = k;
                break;
            }
    for (int i = 1; i <= n; i++)
        cout << i << " " << res[i] << endl;
}
