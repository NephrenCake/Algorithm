#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1017/

/**
 * ״̬��ʾ f[i, j]
 *      ���� ������ߵ�[i, j]����������߷��ļ���
 *      ���� max
 * ״̬����
 *      ���д������������߷����� | ���д�����������߷�����
 * ת�Ʒ���
 *      max(f[i - 1, j], f[i, j - 1]) + w[i, j]
 */

const int N = 110;

int f[N][N];
int r, c;

void sol() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            cin >> f[i][j];
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + f[i][j];
        }

    cout << f[r][c] << endl;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
        sol();
}
