#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int n, m, g[N][N], used[N], dist[N], ans;  // dist 表示点到现有集合的最小距离

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    memset(dist, 0x3f, sizeof dist);
    for (int k = 0; k < n; k++) {
        int t = -1;
        for (int i = 1; i <= n; i++)
            if (!used[i] && (t == -1  || dist[t] > dist[i]))
                t = i;
        if (k && dist[t] == 0x3f3f3f3f) {
            cout << "impossible";
            return 0;
        }
        if (k) ans += dist[t];
        dist[t] = 0;
        used[t] = 1;
        for (int i = 1; i <= n; i++)
            if (dist[i] > g[t][i])
                dist[i] = g[t][i];
    }
    cout << ans;
}
