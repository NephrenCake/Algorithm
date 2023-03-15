#include <iostream>

using namespace std;

const int N = 10010, MOD = 10000;
int p, q, k, a[N];

int main() {
    cin >> a[0] >> a[1] >> p >> q >> k;
    a[0] %= MOD, a[1] %= MOD;
    for (int i = 2; i <= k; i++)
        a[i] = (a[i - 1] * p + a[i - 2] * q) % MOD;
    cout << a[k];
}
