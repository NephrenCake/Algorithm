#include <iostream>

using namespace std;

const int N = 2010, MOD = 1e9 + 7;
int n, a, b, f[N][N];

int main() {
    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= i; j++)
            if (!j) f[i][j] = 1;
            else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;

    cin >> n;
    while (n-- && cin >> a >> b)
        cout << f[a][b] << endl;
}
