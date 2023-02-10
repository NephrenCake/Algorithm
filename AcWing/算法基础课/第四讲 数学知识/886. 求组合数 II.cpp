#include <iostream>

using namespace std;

const int N = 100010, MOD = 1e9 + 7;
int fact[N], infact[N];

typedef long long LL;

int qmi(int a, int k, int p) {  // ¿ìËÙÃÝÄ£°å
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main() {
    int n, a, b;
    cin >> n;

    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL) fact[i - 1] * i % MOD;
        infact[i] = (LL) infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }

    while (n--) {
        cin >> a >> b;
        cout << (LL) fact[a] * infact[b] % MOD * infact[a - b] % MOD << endl;
    }
}
