#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt, phi[N], used[N];

void get_euler(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!used[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            used[t] = 1;
            if (i % primes[j] == 0) {
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
}

int main() {
    long long n, ans = 0;
    cin >> n;
    get_euler(n);
    for (int i = 1; i <= n; i++)
        ans += phi[i];
    cout << ans;
}
