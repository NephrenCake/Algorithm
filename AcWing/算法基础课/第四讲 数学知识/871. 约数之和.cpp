#include <iostream>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;
unordered_map<int, int> m;

void get_divisors(int a) {
    for (int i = 2; i <= a / i; i++)
        while (a % i == 0) a /= i, m[i]++;
    if (a > 1) m[a]++;
}

int main(){
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        get_divisors(a);
    }
    long long ans = 1;
    for (auto i: m) {
        long long t1 = 1;
        while (i.second--) t1 = (t1 * i.first + 1) % MOD;
        ans = (ans * t1) % MOD;
    }
    cout << ans;
}
