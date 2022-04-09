#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 10000000 + 10, MOD = 1000000007;

LL n;
LL f[N];

int main() {
    cin >> n;

    f[1] = 1, f[2] = 2, f[3] = 5;
    for (int i = 4; i <= n; i++) {
        LL s1 = f[i - 1];
        LL s2 = f[i - 2] * 2 % MOD;
        LL s3 = f[i - 3] * 5 % MOD;
        f[i] = (s1 + s2 + s3) % MOD;
    }

    cout << f[n] << endl;
    return 0;
}
