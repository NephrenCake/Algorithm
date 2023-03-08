#include <iostream>
#include <vector>

using namespace std;

#define v first
#define w second
typedef pair<int, int> PII;

const int N = 70, M = 32010;
int n, m, f[M];
PII fa[N];
vector<PII> son[N];

// 2. һά�Ż�
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!c) fa[i] = {a, b * a};
        else son[c].push_back({a, b * a});
    }

    for (int i = 1; i <= n; i++)  // ǰi����Ʒ�顣ÿ����Ʒ���п�����һ���飬���n����Ʒ�飬ʵ���Ƕ��ٸ�����
        for (int j = m; j >= 0; j--)  // ǰj�Ŀռ�
            if (fa[i].v)  // ���п��ޣ���Ϊһάdp״̬�Զ�ת�Ƶ���һ��
                for (int k = 0; k < 1 << son[i].size(); k++) {  // ������ö�٣�ÿλ1��ʾѡ�����Ʒ0��ʾ��ѡ��k��ʾ�ڼ��ֲ���
                    // ����ò���ռ��v�ռ䣬�õ�w��ֵ
                    int v = fa[i].v, w = fa[i].w;
                    for (int l = 0; l < son[i].size(); l++)
                        if (k >> l & 1) {
                            v += son[i][l].v;
                            w += son[i][l].w;
                        }
                    if (j - v >= 0)  // ת�Ʒ���
                        f[j] = max(f[j], f[j - v] + w);
                }
    cout << f[m] << endl;
}

// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// #define v first
// #define w second
// typedef pair<int, int> PII;
//
// const int N = 70, M = 32010;
// int n, m, f[N][M];
// PII fa[N];  // ��ƷiΪ����ʱ������fa[i]
// vector<PII> son[N];  // ��ƷjΪ��Ʒi�ĸ���ʱ������son[i]
//
// // 1. ���ض�ά ������ö��
// int main() {
//     cin >> m >> n;
//     for (int i = 1; i <= n; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;  // �۸� ��Ҫ�� �������Ǹ���
//         if (!c) fa[i] = {a, a * b};
//         else son[c].push_back({a, a * b});
//     }
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++) {
//             // ������i��������ʱ������һ��0�۸�0��ֵ����Ʒ������״̬f��ת��
//             f[i][j] = f[i - 1][j];
//             if (fa[i].v)  // ���п���
//                 for (int k = 0; k < 1 << son[i].size(); k++) {
//                     int v = fa[i].v, w = fa[i].w;
//                     for (int l = 0; l < son[i].size(); l++)
//                         if (k >> l & 1) {
//                             v += son[i][l].v;
//                             w += son[i][l].w;
//                         }
//                     if (j - v >= 0)
//                         f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
//                 }
//         }
//     cout << f[n][m];
// }
