#include <iostream>

using namespace std;

const int MOD = 100003;
typedef long long LL;
LL n, m;

LL qmi(int a, LL b, int p) {
    LL res = 1, t = a;
    while (b) {
        if (b & 1) res = res * t % p;
        t = t * t % p;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> m >> n;
    cout << ((qmi(m, n, MOD) - (LL) m * qmi(m - 1, n - 1, MOD) % MOD) % MOD + MOD) % MOD << endl;
}
