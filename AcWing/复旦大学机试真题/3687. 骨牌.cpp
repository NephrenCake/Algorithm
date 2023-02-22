#include <iostream>

using namespace std;

const int N = 10010, MOD = 999983;
int n, f[N];

int main() {
    cin >> n;
    // f[i] 前2*n的地板有多少种铺法
    // 竖着 f[i - 1] | 横着 f[i - 2];
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (i - 2 >= 0) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    cout << f[n];
}
