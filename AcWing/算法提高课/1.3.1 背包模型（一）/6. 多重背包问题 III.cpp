#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 20010;
int n, m, s[N], v[N], w[N], f[N][M], q[M];
// qΪ�������У�����Ǵ��������ֵ���±�
// q�����ݼ�������ά�����ֵ�����������ֵ���±�Ϊ��ͷԪ�أ����������ֵΪq[hh]

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++) {  // ������Ʒ��ǰi����Ʒ
        // ѭ��O(M)
        for (int r = 0; r < v[i]; r++) {  // ��������
            int hh = 0, tt = -1;
            for (int j = r; j <= m; j += v[i]) {  // �����ռ䣬ǰj�Ŀռ�
                while (hh <= tt && j - q[hh] > s[i] * v[i]) hh++;
                //     hh <= tt ���в���
                //                 j - q[hh] �Ǽƻ�����װ��i����Ʒ�Ŀռ�
                //                         ���� s[i] * v[i] ��s����i����Ʒ�����ۿռ�
                while (hh <= tt && f[i - 1][q[tt]] + (j - q[tt]) / v[i] * w[i] <= f[i - 1][j]) --tt;
                //     hh <= tt ���в���
                //                               װ�� (j - q[tt]) / v[i] ����Ʒ
                //                             ��ֵΪ (j - q[tt]) / v[i] * w[i]
                q[++tt] = j;
                f[i][j] = f[i - 1][q[hh]] + (j - q[hh]) / v[i] * w[i];
            }
        }
    }
    cout << f[n][m];
}
