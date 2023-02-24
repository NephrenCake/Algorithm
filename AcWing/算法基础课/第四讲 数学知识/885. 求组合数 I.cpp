#include <iostream>

using namespace std;

const int N = 2010, MOD = 1e9 + 7;
int n, a, b, f[N][N];

int main() {
    cin >> n;
    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) f[i][j] = 1;
            else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
    while (n-- && cin >> a >> b)
        cout << f[a][b] << endl;
}
