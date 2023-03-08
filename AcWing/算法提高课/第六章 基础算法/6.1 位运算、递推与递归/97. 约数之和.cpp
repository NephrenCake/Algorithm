#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long ULL;
const int MOD = 9901;
ULL ans = 1;
unordered_map<int, int> m;

void get_div(int x) {
    for (int i = 2; i <= x / i; i++)
        while (x % i == 0) x /= i, m[i]++;
    if (x > 1) m[x]++;
}

ULL qmi(int a, int b, int p) {
    ULL res = 1, t = a;
    while (b) {
        if (b & 1) res = res * t % p;
        t = t * t % p;
        b >>= 1;
    }
    return res;
}

ULL get_sum(int p, int k) {  // k表示有几个项，即p(0) + ... + p(k - 1)，调用时是求p(0) + ... + p(k)
    if (k == 1) return 1;
    if (k & 1) return 1 + p * get_sum(p, k - 1) % MOD;
    return (1 + qmi(p, k / 2, MOD)) * get_sum(p, k / 2) % MOD;
}

int main() {
    int a, b;
    cin >> a >> b;
    get_div(a);
    for (auto it: m) {
        int k = it.first, v = it.second * b;
        ans = ans * get_sum(k, v + 1) % MOD;
    }
    if (a == 0) cout << 0;
    else cout << ans;
}

// // Time Limit Exceeded
// #include <iostream>
// #include <unordered_map>
//
// using namespace std;
//
// const int MOD = 9901;
// int ans = 1;
// unordered_map<int, int> m;
//
// void get_div(int x) {
//     for (int i = 2; i <= x / i; i++)
//         while (x % i == 0) x /= i, m[i]++;
//     if (x > 1) m[x]++;
// }
//
// int main() {
//     int a, b;
//     cin >> a >> b;
//     get_div(a);
//     for (auto it: m) {
//         int k = it.first, v = it.second * b, t = 1;
//         while (v--) t = (t * k + 1) % MOD;
//         ans = ans * t % MOD;
//     }
//     cout << ans;
// }
