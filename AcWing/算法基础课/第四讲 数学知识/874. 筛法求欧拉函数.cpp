#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, used[N], phi[N], primes[N], cnt;

void get_phi(int x) {
    phi[1] = 1;
    for (int i = 2; i <= x; i++) {
        if (!used[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++) {  // ȡ�Ⱥ�
            used[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];  // phi[i]
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);  // (primes[j] - 1)
        }
    }
}

int main() {
    cin >> n;
    get_phi(n);
    long long ans = 0;  // ��LL
    for (int i = 1; i <= n; i++)
        ans += phi[i];
    cout << ans;
}
