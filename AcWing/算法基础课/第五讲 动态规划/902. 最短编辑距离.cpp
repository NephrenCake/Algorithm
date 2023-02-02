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
    for (int i = 1; i <= m; i++) f[0][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            // f[i][j] a的1~i子串变成b的1~j子串，至少需要进行的次数
            // 最后一步是增加最后一个字母 | 最后一步是删除最后一个字母 | 最后一步是修改最后一个字母
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    cout << f[n][m];
}
