#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1052/

/**
 * ����Ӱ����ʱ�ж����ֲ�ͬ�ķ��䷽��
 * ״̬��ʾ f[i][j]
 *      ���� ��������Ϊ i���������Ϊ j �ķ��䷽������
 *      ���� count
 * ״̬����
 *      ��СֵΪ 0 | ��Сֵ��Ϊ 0
 *      f[i][j] = f[i][j - 1] + f[i - j][j];
 */

const int N = 15;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;  // ���������Ϊ M��Ӱ����ĸ������Ϊ N��
        int f[N][N] = {0};

        f[0][0] = 1;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i][j - 1];
                if (i >= j)
                    f[i][j] += f[i - j][j];
            }
        cout << f[m][n] << endl;
    }
}
