#include <iostream>

using namespace std;

const int MOD = 200907;
typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1, t = a;
    while (b) {
        if (b & 1) res = res * t % p;
        t = t * t % p;
        b >>= 1;
    }
    return res;
}

LL qad(int a, int b, int p) {
    LL res = 0, t = a;
    while (b) {
        if (b & 1) res = (res + t) % p;
        t = (t + t) % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int t, a, b, c, k;
    cin >> t;
    while (t-- && cin >> a >> b >> c >> k)
        if (c - b == b - a)
            cout << (a + qad(c - b, k - 1, MOD)) % MOD << endl;
        else
            cout << a * qmi(c / b, k - 1, MOD) % MOD << endl;
}
