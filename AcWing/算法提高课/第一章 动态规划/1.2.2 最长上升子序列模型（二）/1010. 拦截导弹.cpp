#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], f[N], ans, g[N], cnt;

int main() {
    for (int t; cin >> t;) a[++n] = t;

    for (int i = n; i >= 1; i--) {
        f[i] = 1;
        for (int j = n; i < j; j--)
            if (a[i] >= a[j])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        int p = -1;
        for (int j = 0; j < cnt; j++)
            if (g[j] >= a[i] && (p == -1 || g[p] > g[j]))
                p = j;
        if (p == -1) p = cnt++;
        g[p] = a[i];
    }
    cout << cnt;
}
