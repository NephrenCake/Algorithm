#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3/

// 01 ������f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i])
// ��ȫ������f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];


// ��2���Ż�
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            // f[i][j] = f[i - 1][j];  // 1. �����ұߣ�������ߣ�����ұ�����һ��ļ�¼�����Ƶ���һ��ļ�¼���ȼۣ�
            // f[j] = f[j];  // 2. �����벻д�ȼ�
            if (v[i] <= j) {
                // f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);  // 1. ��������ͬһ��ά�Ȳ�����ȥ����һά��Ȼ�ȼ�
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }

    cout << f[m];  // ���ݶ���������
}

// const int N = 1010;
// int n, m;
// int v[N], w[N];
// int f[N][N];
//
//
// ��1������
// int main(){
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i) {
//         cin >> v[i] >> w[i];
//     }
//
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 0; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];
//             if (v[i] <= j)
//                 f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//
//     cout << f[n][m];
// }