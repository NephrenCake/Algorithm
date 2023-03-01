#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, primes[N], cnt, used[N];

void get_primes(int x) {
    for (int i = 2; i <= n; i++) {
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
    for (int i = 0; i < cnt; i++) {
        int t = n, res = 0;
        while (t) {
            res += t / primes[i];
            t /= primes[i];
        }
        cout << primes[i] << " " << res << endl;
    }
}

// // Time Limit Exceeded
// #include <iostream>
// #include <map>
//
// using namespace std;
//
// int n;
// map<int, int> m;
//
// void get_div(int x) {
//     for (int i = 2; i <= x / i; i++)
//         while (x % i == 0) x /= i, m[i]++;
//     if (x > 1) m[x]++;
// }
//
// int main() {
//     cin >> n;
//     for (int i = n; i > 1; i--)
//         get_div(i);
//     for (auto it: m)
//         cout << it.first << " " << it.second << endl;
// }
