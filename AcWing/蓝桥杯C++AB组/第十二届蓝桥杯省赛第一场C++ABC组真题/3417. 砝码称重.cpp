#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3420/

/**
 * ״̬��ʾ f[i][j]
 *      ���� ����ֻ����ǰ i �����룬���ճƵ�����Ϊ j �ķ����ļ���
 *      ���� bool�Ƿ����
 * ״̬����
 *      �������� | ������� | �����ұ�
 *      f[i - 1][j] | f[i - 1][j - w[i]] | f[i - 1][j + w[i]]
 *
 * �����ڹ����п��ԳƳ������������Ҫ�����������ȣ��������������һ��ƫ����
 */

const int N = 110, M = 2e5 + 10, B = M / 2;

int n, m, w[N];
bool f[N][M];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        m += w[i];
    }

    f[0][B] = true;
    for (int i = 1; i <= n; i++)
        for (int j = -m; j <= m; j++) {
            f[i][j + B] = f[i - 1][j + B];
            if (j - w[i] >= -m) f[i][j + B] |= f[i - 1][j - w[i] + B];
            if (j + w[i] <= m) f[i][j + B] |= f[i - 1][j + w[i] + B];
        }

    int ans = 0;
    for (int j = 1; j <= m; j++)
        ans += f[n][j + B];
    cout << ans;
}
