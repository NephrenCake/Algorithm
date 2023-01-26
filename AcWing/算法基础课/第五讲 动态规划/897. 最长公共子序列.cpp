#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
string s1, s2;
int n, m, f[N], g[N];

// 2. 滚动数组优化
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
// 1. 二维朴素
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
