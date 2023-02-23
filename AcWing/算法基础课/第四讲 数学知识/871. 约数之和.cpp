#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long ULL;
const int MOD = 1e9 + 7;
int n, a;
unordered_map<int, int> m;

void get_div(int x) {
    for (int i = 2; i <= x / i; i++)
        while (x % i == 0) x /= i, m[i]++;
    if (x > 1) m[x]++;
}

int main() {
    cin >> n;
    while (n-- && cin >> a) get_div(a);

    ULL ans = 1;
    for (auto it: m) {
        int k = it.first, v = it.second;
        ULL t = 1;
        while (v--) t = (t * k + 1) % MOD;
        ans = (ans * t) % MOD;
    }
    cout << ans;
}
