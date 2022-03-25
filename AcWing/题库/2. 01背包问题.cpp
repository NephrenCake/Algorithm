#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/2/

// ��2���Ż��ռ�
const int N = 1010;
int n, m;  // ��Ʒ�����ͱ����ݻ�
int v[N], w[N];
int f[N];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j) {
            if (j >= v[i]) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);  // �����Ұ�ߵ��Ӽ�����״̬
                // f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
                // ע��ԭʽ�� f[i - 1][j - v[i]] ȡ���� [i - 1] ״̬�µ���Ϣ���� j ��ѭ������������Ϣ�Ѿ����ı�
            }
        }
    }

    cout << f[m] << endl;
}

// ��1������dp
// const int N = 1010;
// int n, m;  // ��Ʒ�����ͱ����ݻ�
// int v[N], w[N];
// int f[N][N];
//
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i) {
//         cin >> v[i] >> w[i];
//     }
//
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];  // ���ߵ��Ӽ�
//             if (j >= v[i]) {
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);  // �����Ұ�ߵ��Ӽ�����״̬
//             }
//         }
//     }
//
//     cout << f[n][m] << endl;
// }
