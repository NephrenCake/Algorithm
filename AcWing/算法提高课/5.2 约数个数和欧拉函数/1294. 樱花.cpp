#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e6 + 10, MOD = 1e9 + 7;
int n, used[N], primes[N], cnt;
LL ans = 1;

void get_primes(int x) {
    for (int i = 2; i <= n; i++) {
        if (!used[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++) {
            used[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;
    get_primes(n);
    for (int i = 0; i < cnt; i++) {
        LL p = primes[i], num = 0, t = n;
        while (t) num += t / p, t /= p;
        ans = ans * (num * 2 + 1) % MOD;
    }
    cout << ans;
}
