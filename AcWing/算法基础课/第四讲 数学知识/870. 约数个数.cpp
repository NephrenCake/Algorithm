#include <iostream>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;
int n, a, ans = 1;
unordered_map<int, int> m;

void get_div(int x) {
    for (int i = 2; i <= x / i; i++)
        while (x % i == 0) x /= i, m[i]++;
    if (x > 1) m[x]++;
}

int main() {
    cin >> n;
    while (n-- && cin >> a)
        get_div(a);
    for (auto it: m)
        ans = (long long) (it.second + 1) * ans % MOD;
    cout << ans;
}
