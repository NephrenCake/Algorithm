#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, primes[N], cnt, used[N], col[N], ans;

void get_primes(int x) {
    for (int i = 2; i <= x; i++) {
        if (!used[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++) {
            used[primes[j] * i] = 1;
            col[primes[j] * i] = 1;
            ans = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;
    get_primes(n + 1);
    cout << ans + 1 << endl;
    for (int i = 2; i <= n + 1; i++) cout << col[i] + 1 << " ";
}
