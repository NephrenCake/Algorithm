#include <iostream>

using namespace std;

const int N = 1010;
int n, m, f[N][N];
string a, b;

int main() {
    cin >> n >> a >> m >> b;
    a = " " + a;
    b = " " + b;

    // f[i][j] a串1~i，b串1~j且以b[j]结尾，的最短编辑距离
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1];
            else {
                f[i][j] = f[i - 1][j - 1];
                f[i][j] = min(f[i][j], f[i - 1][j]);
                f[i][j] = min(f[i][j], f[i][j - 1]);
                f[i][j]++;
            }
    cout << f[n][m];
}
