#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;
int n, w, a[N], g[N], ans = 0x3f3f3f3f;

void dfs(int idx, int cnt) {
    if (cnt >= ans) return;
    if (idx == -1) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 1; i <= cnt; i++)
        if (a[idx] + g[i] <= w) {
            g[i] += a[idx];
            dfs(idx - 1, cnt);
            g[i] -= a[idx];
        }
    g[cnt + 1] += a[idx];
    dfs(idx - 1, cnt + 1);
    g[cnt + 1] -= a[idx];
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    dfs(n - 1, 1);
    cout << ans;
}
