#include <iostream>

using namespace std;

const int N = 1010;
int c, n, primes[N], cnt, used[N], phi[N];

void get_phi(int x) {
    phi[1] = 1;
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
    get_phi(1000);
    for (int i = 2; i <= 1000; i++) phi[i] += phi[i - 1];
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cin >> n;
        printf("%d %d %d \n", i, n, phi[n] * 2 + 1);
    }
}
