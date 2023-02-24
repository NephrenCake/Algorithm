#include <iostream>

using namespace std;

const int N = 2e5 + 10, MOD = 1e9 + 7;
typedef long long LL;
LL fact[N], infact[N];

LL qmi(int a, int b, int p) {
    LL res = 1, t = a;
    while (b) {
        if (b & 1) res = res * t % p;
        t = t * t % p;
        b >>= 1;
    }
    return res;
}

int main() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        fact[i] = fact[i - 1] * i % MOD, infact[i] = infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    int n;
    cin >> n;
    cout << fact[2 * n] * infact[n] % MOD * infact[n] % MOD * qmi(n + 1, MOD - 2, MOD) % MOD << endl;
}
