#include <iostream>

using namespace std;

const int N = 2010, MOD = 1e9 + 7;
int n, a, b, c[N][N];

int main() {
    cin >> n;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;

    while (n--) {
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
}
