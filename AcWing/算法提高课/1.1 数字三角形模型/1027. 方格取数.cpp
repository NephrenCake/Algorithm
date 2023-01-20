#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;
int n, f[N * 2][N][N], w[N][N];

int main() {
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
        w[a][b] = c;

    for (int k = 2; k <= 2 * n; k++)  // k = i1 + j1 = i2 + j2
        for (int i1 = 1; i1 <= min(k - 1, n); i1++)
            for (int i2 = 1; i2 <= min(k - 1, n); i2++) {
                int j1 = k - i1, j2 = k - i2;  // j����Ϊ1
                int t = i1 == i2 ? w[i1][j1] : w[i1][j1] + w[i2][j2];  // �����ߵ���λ����ͬ����ֻ��һ��
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2 - 1] + t);  // 1��2��
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2 - 1] + t);  // 1��2��
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2] + t);  // 1��2��
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2] + t);  // 1��2��
            }
    cout << f[2 * n][n][n];
}
