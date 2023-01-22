#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m, f[N][N], v[N], w[N], p[N][N];

int main() {
    cin >> n >> m;  // ��Ʒ�����ͱ����ݻ�
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];  // ����ͼ�ֵ

    for (int i = n; i; i--)  // ע�⣡dp�Ӻ���ǰ����ÿ����Ʒ�������ֵ�����С����
        for (int j = 1; j <= m; j++)
            f[i][j] = j - v[i] >= 0 ? max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]) : f[i + 1][j];

    int t = m;
    for (int i = 1; i <= n; i++) {
        if (t >= v[i] && f[i][t] == f[i + 1][t - v[i]] + w[i]) {
            cout << i << " ";
            t -= v[i];
        }
    }
}
