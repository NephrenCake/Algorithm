#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int m, f[N];
int v[5] = {0, 10, 20, 50, 100};

// 2. 一维优化
int main() {
    cin >> m;

    f[0] = 1;
    for (int i = 1; i <= 4; i++)  // 前i种书
        for (int j = 0; j <= m; j++)
            if (j - v[i] >= 0)
                f[j] += f[j - v[i]];
    cout << f[m];
}

// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 1010;
// int m, f[5][N];
// int v[5] = {0, 10, 20, 50, 100};
//
// 1. 朴素
// int main() {
//     cin >> m;
//
//     f[0][0] = 1;
//     for (int i = 1; i <= 4; i++)  // 前i种书
//         for (int j = 0; j <= m; j++)
//             f[i][j] = j - v[i] >= 0 ? f[i - 1][j] + f[i][j - v[i]] : f[i - 1][j];
//     // for (int i = 1; i <= 4; i++)  // 前i种书
//     //     for (int r = 0; r < v[i]; r++)  // 余数r
//     //         for (int j = r; j <= m; j += v[i]) {
//     //             if (j - v[i] >= 0)
//     //                 f[i][j] = f[i - 1][j] + f[i][j - v[i]];
//     //             else
//     //                 f[i][j] = f[i - 1][j];
//     //         }
//     cout << f[4][m];
// }
