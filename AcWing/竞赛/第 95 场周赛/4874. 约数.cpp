#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 10;
ULL n, a, primes[N], cnt;
bool used[N];

void get_b(ULL x) {
    used[1] = 1;
    for (ULL i = 2; i <= x; i++) {
        if (!used[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++) {
            used[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    get_b(N);
    cin >> n;
    while (n-- && cin >> a) {
        ULL t = sqrt(a);
        if (t * t == a && used[t] == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
