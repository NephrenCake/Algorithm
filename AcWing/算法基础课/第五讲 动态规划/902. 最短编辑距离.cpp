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
            // f[i][j] a��1~i�Ӵ����b��1~j�Ӵ���������Ҫ���еĴ���
            // ���һ�����������һ����ĸ | ���һ����ɾ�����һ����ĸ | ���һ�����޸����һ����ĸ
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    cout << f[n][m];
}
