#include <iostream>

using namespace std;

const int N = 1e7 + 10;
int n, primes[N], cnt, used[N];
long long phi[N], ans;

void get_phi(int x) {
    for (int i = 2; i <= x; i++) {
        if (!used[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++) {
            used[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}

int main() {
    cin >> n;
    get_phi(n);
    for (int i = 2; i <= n; i++)
        phi[i] += phi[i - 1];
    for (int i = 0; i < cnt; i++)
        ans += phi[n / primes[i]] * 2 + 1;
    cout << ans;
}
