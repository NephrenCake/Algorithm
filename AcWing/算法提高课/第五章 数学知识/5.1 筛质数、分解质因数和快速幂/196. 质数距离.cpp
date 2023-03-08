#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int used[N], primes[N], cnt;

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
    int a, b;
    while (cin >> a >> b) {
        memset(used, 0, sizeof used);
        memset(primes, 0, sizeof primes);
        cnt = 0;
        get_primes(sqrt(b));
        memset(used, 0, sizeof used);
        for (int i = 0; i < cnt; i++)
            for (LL j = max(((LL) a + primes[i] - 1) / primes[i], (LL) 2) * primes[i]; j <= b; j += primes[i])
                used[j - a] = 1;
        memset(primes, 0, sizeof primes);
        // exit(1);
        cnt = 0;
        for (int i = 0; i <= b - a; i++)
            if (!used[i] && i + a > 1)
                primes[cnt++] = i + a;
        if (cnt < 2) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }
        int c = 1, d = 1;
        for (int i = 2; i < cnt; i++) {
            if (primes[c] - primes[c - 1] > primes[i] - primes[i - 1]) c = i;
            if (primes[d] - primes[d - 1] < primes[i] - primes[i - 1]) d = i;
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", primes[c - 1], primes[c], primes[d - 1], primes[d]);
    }
}
