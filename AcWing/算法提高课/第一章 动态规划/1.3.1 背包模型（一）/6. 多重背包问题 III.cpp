#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 20010;
int n, m, s, v, w, f[N][M];
// qΪ�������У�����Ǵ��������ֵ���±�
// q�����ݼ�������ά�����ֵ�����������ֵ���±�Ϊ��ͷԪ�أ����������ֵΪq[hh]

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {  // ������Ʒ��ǰi����Ʒ
        cin >> v >> w >> s;
        // ѭ��O(M)
        for (int r = 0; r < v; r++) {  // ��������
            int q[M], hh = 0, tt = -1;
            for (int j = r; j <= m; j += v) {  // �����ռ䣬ǰj�Ŀռ�
                while (hh <= tt && q[hh] < j - s * v) hh++;  // С������Ϊ���Ϊ0ʱ��ȡ
                //     hh <= tt ���в���
                //                 j - q[hh] �Ǽƻ�����װ��i����Ʒ�Ŀռ�
                //                         ���� s[i] * v[i] ��s����i����Ʒ�����ۿռ�
                while (hh <= tt && f[i - 1][q[tt]] + (j - q[tt]) / v * w <= f[i - 1][j]) --tt;  // �Ƿ���ڲ���Ҫ
                //     hh <= tt ���в���
                //                               װ�� (j - q[tt]) / v[i] ����Ʒ
                //                             ��ֵΪ (j - q[tt]) / v[i] * w[i]
                q[++tt] = j;
                f[i][j] = f[i - 1][q[hh]] + (j - q[hh]) / v * w;
            }
        }
    }
    cout << f[n][m];
}
