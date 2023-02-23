#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010, MOD = 1e9 + 7;
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
    int n, a, b;
    cin >> n;
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        infact[i] = infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }
    while (n-- && cin >> a >> b)
        cout << (LL) fact[a] * infact[b] % MOD * infact[a - b] % MOD << endl;
}
