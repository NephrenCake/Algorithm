#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30, M = 30010;
int n, m, v[N], w[N], f[N][M];

int main() {
    cin >> m >> n;  // ��Ǯ�� ��Ʒ�ĸ���
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)  // ǰi����Ʒ
        for (int j = 1; j <= m; j++) {  // ǰj��Ǯ
            f[i][j] = f[i - 1][j];
            if (j - v[i] >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i] * w[i]);
        }
    cout << f[n][m];
}
