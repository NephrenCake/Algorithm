#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a, primes[N], cnt, used[N], is_primes[N];

int get_primes(int x) {
    for (int i = 2; i <= x; i++) {
        if (!used[i]) primes[cnt++] = i, is_primes[i] = 1;
        for (int j = 0; primes[j] <= x / i; j++) {
            used[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    get_primes(1e6);
    while (cin >> a, a) {
        int p1, p2;
        for (int i = 1; i < cnt; i++) {
            p1 = primes[i], p2 = a - p1;
            if (is_primes[p2])
                break;
        }
        printf("%d = %d + %d\n", a, p1, p2);
    }
}
