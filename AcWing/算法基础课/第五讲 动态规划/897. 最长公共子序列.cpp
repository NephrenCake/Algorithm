#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
string s1, s2;
int n, m, f[N], g[N];

// 2. ���������Ż�
int main() {
    cin >> n >> m >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;

    for (int i = 1; i <= n; i++) {
        memcpy(g, f, sizeof f);
        for (int j = 1; j <= m; j++) {
            f[j] = max(f[j - 1], g[j]);
            if (s1[i] == s2[j])
                f[j] = max(f[j], g[j - 1] + 1);
        }
    }
    cout << f[m];
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 1010;
// string s1, s2;
// int n, m, f[N][N];
//
// 1. ��ά����
// int main() {
//     cin >> n >> m >> s1 >> s2;
//     s1 = " " + s1;
//     s2 = " " + s2;
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++) {
//             f[i][j] = max(f[i][j - 1], f[i - 1][j]);
//             if (s1[i] == s2[j])
//                 f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
//         }
//     cout << f[n][m];
// }

// #include <iostream>
//
// using namespace std;
//
// const int N = 1010;
// int n, m, f[N][N], ans;
// string a, b;
//
// int main() {
//     cin >> n >> m >> a >> b;
//     a = " " + a;
//     b = " " + b;
//
//     // f[i][j] a��1~i����ĸ����a[i]��β��b��1~j����ĸ����b[j]��β��������������г���
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++) {
//             f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//             if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
//             ans = max(ans, f[i][j]);
//         }
//     cout << ans;
// }
