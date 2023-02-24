#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << 20;
int n, a[N][N], f[M][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    // f[i][j] ��0�ߵ�j��������״̬Ϊi�ģ�����·����Сֵ
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)  // ��ѭ������״̬i
        for (int j = 0; j < n; j++)  // ��ѭ�����յ���ڵ�j
            if (i >> j & 1)  // Ҫ�ﵽj�ڵ㣬�����������ĵ㼯״̬i�������j������Ϊ�Ƿ�
                for (int k = 0; k < n; k++)  // ����ÿ������j��k
                    if ((i - (1 << j)) >> k & 1)  // Ҫ�ﵽk�ڵ㣬�����������ĵ㼯״̬i(��ȥj)�������k������Ϊ�Ƿ�
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);
    cout << f[(1 << n) - 1][n - 1];  // ���е㶼�߹���,���յ���n-1����̾���
}
