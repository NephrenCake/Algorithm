#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n, m, c[N], v[N][N], w[N][N], f[N][N];


int main() {
    cin >> n >> m;  // ��Ʒ��������������
    for (int i = 1; i <= n; i++) {  // ��Ʒ����
        cin >> c[i];  // ÿ�����
        for (int j = 1; j <= c[i]; j++)  // ����ͼ�ֵ
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++) {  // ǰi����Ʒ/��
        for (int j = 1; j <= m; j++) {  // ǰj���ռ�
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
