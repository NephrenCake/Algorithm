#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, v, a[N][2], f[N];

// 2. ¿Õ¼äÓÅ»¯
int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1];

    for (int i = 1; i <= n; i++)
        for (int j = v; j ; j--) {
            // f[j] = f[j];
            if (j - a[i][0] >= 0)
                f[j] = max(f[j], f[j - a[i][0]] + a[i][1]);
        }
    cout << f[v];
}

// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// const int N = 1010;
// int n, v, a[N][2], f[N][N];
//
// 1. ÆÓËØ
// int main() {
//     cin >> n >> v;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i][0] >> a[i][1];
//
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= v; j++) {
//             f[i][j] = f[i - 1][j];
//             if (j - a[i][0] >= 0)
//                 f[i][j] = max(f[i][j], f[i - 1][j - a[i][0]] + a[i][1]);
//         }
//     cout << f[n][v];
// }
