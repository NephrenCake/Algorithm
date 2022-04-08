#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n = 2021041820210418;

vector<LL> get_divisors(LL n) {
    vector<LL> res;
    for (LL i = 1; i <= n / i; i++)
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    // sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<LL> divisors = get_divisors(n);
    int m = divisors.size();    // 128

    LL ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                if (divisors[i] * divisors[j] * divisors[k] == n)
                    ans++;

    printf("%lld", ans);
    return 0;
}
