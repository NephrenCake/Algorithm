#include <iostream>

using namespace std;

const int N = 1e6;
int k, used[N], primes[N], cnt;

void get_primes() {
    for (int i = 2; i < N; i++) {
        if (!used[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] < N / i; j++) {
            used[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    get_primes();
    while (cin >> k) cout << primes[k - 1] << endl;
}
