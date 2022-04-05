#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.acwing.com/problem/content/3494/

/**
 * f[i, a, b, k]: ��ʾ�Ѿ��ź���ǰi - 1�У���i - 2�е�״̬��a, ��i - 1�е�״̬��b, ������ k ƥ��ķ����ļ���
 * ����� i �е�״̬�� c
 * a��b��c�Ƕ��������� ����˵c=10010, ��ʾ��i�еĵ�0�к͵�3���������һƥ��
 *
 * ״̬ת��: f[i,b,c,k] += f[i - 1, a, b, k - t]
 */

const int N = 110, M = 1 << 6, K = 21, MOD = 1e9 + 7;

int n, m, k;  // ���̵���������������ĸ���
long long f[N][M][M][K];

int get_count(int x) {  // ���㵱ǰ�������˶��ٸ�1
    int res = 0;
    for (; x; x -= (x & -x))res++;
    return res;
}

int main() {
    cin >> n >> m >> k;
    int max_n = 1 << n;
    f[0][0][0][0] = 1;  // ��ʼ��
    for (int i = 1; i <= m; i++)
        for (int a = 0; a < max_n; a++)
            for (int b = 0; b < max_n; b++) {
                if ((a >> 2) & b || a & (b >> 2)) continue;  // �ж�ǰǰ�к�ǰ����û�з�����ͻ��֦
                for (int c = 0; c < max_n; c++) {
                    if ((c >> 2) & b || c & (b >> 2)) continue;  // �ж�ǰ�к͵�ǰ����û�з�����ͻ
                    if ((c >> 1) & a || c & (a >> 1)) continue;  // �ж�ǰǰ�к͵�ǰ����û�з�����ͻ
                    int t = get_count(c);
                    for (int j = t; j <= k; j++)  // �����������
                        f[i][b][c][j] = (f[i][b][c][j] + f[i - 1][a][b][j - t]) % MOD;
                }
            }
    int res = 0;
    for (int i = 0; i < max_n; i++)//��ǰǰ�к�ǰ�в�ͬ��״̬�����ж��ٸ����԰ڷŵķ�����
        for (int j = 0; j < max_n; j++)
            res = (res + f[m][i][j][k]) % MOD;
    cout << res;
}
