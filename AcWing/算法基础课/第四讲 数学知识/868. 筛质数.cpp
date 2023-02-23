#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, used[N], primes[N], cnt;

void get_primes(int x) {
    for (int i = 2; i <= x; i++) {
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
    cout << cnt;
}
