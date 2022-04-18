#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL a, b, n;
LL ans = 0;

int main() {
    cin >> a >> b >> n;
    // 1000000000 2000000000 1000000000000000000
    LL cnt1_5 = a * 5, cnt6_7 = b * 2;

    ans = (n / (cnt1_5 + cnt6_7)) * 7;  // 用多少整周，加到结果里
    n %= (cnt1_5 + cnt6_7);
    if (n == 0) {
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= 5; i++) {
        n -= a;
        ans += 1;
        if (n <= 0) {
            cout << ans << endl;
            return 0;
        }
    }
    for (int i = 6; i <= 7; i++) {
        n -= b;
        ans += 1;
        if (n <= 0) {
            cout << ans <<endl;
            return 0;
        }
    }
    return 0;
}
