#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000, M = 100000 + 10, MOD = 1000000007;

int n;  // 每一数位最高为 N 进制,最低为二进
int ma, mb, a[M], b[M];  // a > b
int wq[M];

int main() {
    cin >> n;
    cin >> ma;
    for (int i = ma - 1; i >= 0; i--)
        cin >> a[i];
    cin >> mb;
    for (int i = mb - 1; i >= 0; i--)
        cin >> b[i];

    for (int i = 0; i < ma; i++) {
        int max_w = N, min_w = max(max(a[i], b[i]) + 1, 2);
        wq[i] = min_w;
        if (i > 0)
            wq[i] *= wq[i - 1];
    }

    int ans = a[0] - b[0];
    for (int i = 1; i < ma; i++) {
        ans += (a[i] - b[i]) * wq[i - 1] % MOD;
    }
    cout << ans << endl;
    return 0;
}
