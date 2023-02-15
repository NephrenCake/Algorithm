#include <iostream>

using namespace std;

const int N = 1010;
int n, m, f[N][N];
string a, b;

int main() {
    cin >> n >> a >> m >> b;
    a = " " + a;
    b = " " + b;

    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;
    // f[i][j] a´®1~i£¬b´®1~jÇÒÒÔb[j]½áÎ²£¬µÄ×î¶Ì±à¼­¾àÀë
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
            else {
                f[i][j] = f[i - 1][j - 1];
                f[i][j] = min(f[i][j], f[i - 1][j]);
                f[i][j] = min(f[i][j], f[i][j - 1]);
                f[i][j]++;
            }
        }
    cout << f[n][m];
}
