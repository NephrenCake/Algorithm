#include<iostream>

using namespace std;

typedef long long LL;
const int N = 110, MOD = 20123;
int fact[N] = {1}, r[N]; // fact预处理10的幂, r预处理某一个数后面的数

int main() {
    for (int i = 1; i <= 101; i++)
        fact[i] = fact[i - 1] * 10 % MOD;
    for (string s; cin >> s;) {
        LL n = s.size(), l = 0, res = 0;
        for (int i = n - 1; i >= 0; i--)
            r[n - i] = (fact[n - i - 1] * (s[i] - '0') + r[n - i - 1]) % MOD;
        for (int i = 0; i < n; i++) {
            int m = s[i] - '0', p = fact[n - i - 1];
            res = (res + 2 * l * p) % MOD;
            if (m > 2) res = (res + 2 * p) % MOD;
            else if (m == 2) res = (res + p + r[n - i - 1] + 1) % MOD;
            else if (m == 1) res = (res + r[n - i - 1] + 1) % MOD;
            l = (l * 10 + m) % MOD;
        }
        cout << res << endl;
    }
}
