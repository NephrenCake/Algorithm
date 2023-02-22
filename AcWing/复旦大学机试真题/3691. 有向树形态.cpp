#include <iostream>

using namespace std;

const int N = 41;
int n;
long long f[N][N];

int main() {
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    cout << f[2 * n][n] / (n + 1);
}
