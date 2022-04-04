#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1072/

/**
 * ״̬��ʾ
 *      ���� ���н� [i, j] ��ɺϷ��������еķ����ļ���
 *      ���� min
 * ״̬����
 *      (A) | AB
 *
 */

const int N = 110, INF = 0x3f3f3f;

string str;
int f[N][N], n;

bool is_match(char l, char r) {
    if (l == '(' && r == ')') return true;
    if (l == '[' && r == ']') return true;
    if (l == '{' && r == '}') return true;
    return false;
}

int main() {
    cin >> str;
    n = str.size();

    for (int len = 1; len <= n; len++)
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            f[i][j] = INF;
            // ��뼯��
            if (is_match(str[i], str[j])) f[i][j] = f[i + 1][j - 1];
            f[i][j] = min(f[i][j], min(f[i + 1][j], f[i][j - 1]) + 1);
            // �Ұ뼯��
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }

    cout << f[0][n - 1];
}