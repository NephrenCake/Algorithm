#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10, MOD = 1e9 + 7;
typedef long long LL;
LL n, m, a[N], g[N], f[N], in[N], out[N], edt;
vector<int> forw[N], back[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];  // 每个实验完成所需要的时间
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;  // u是v的前置
        forw[u].push_back(v);
        back[v].push_back(u);
        out[u]++, in[v]++;
    }

    // 向前
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);
    while (q.size()) {
        int p = q.front();
        q.pop();
        edt = max(edt, f[p] + a[p]);
        for (auto ne: forw[p]) {
            f[ne] = max(f[ne], f[p] + a[p]);
            if (--in[ne] == 0)
                q.push(ne);
        }
    }

    // 向后
    for (int i = 1; i <= n; i++)
        if (out[i] == 0)
            q.push(i), g[i] = edt - a[i];
        else
            g[i] = edt;
    while (q.size()) {
        int p = q.front();
        q.pop();
        for (auto ne: back[p]) {
            g[ne] = min(g[ne], g[p] - a[ne]);
            if (--out[ne] == 0)
                q.push(ne);
        }
    }

    // 计算公式
    LL ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * (g[i] - f[i] + 1)) % MOD;
    }
    cout << edt << endl << ans;
}
