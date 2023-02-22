#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int n, m, g[N][N], dist[N], used[N], sum, cnt;

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (int i = 1, a, b, c; i <= m; i++) cin >> a >> b >> c, g[b][a] = g[a][b] = min(g[a][b], c);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        int p = -1;
        for (int j = 1; j <= n; j++)
            if (!used[j] && (p == -1 || dist[p] > dist[j]))
                p = j;
        used[p] = 1;
        if (dist[p] == 0x3f3f3f3f) break;
        sum += dist[p];
        cnt++;
        for (int j = 1; j <= n; j++)
            if (!used[j] && dist[j] > g[p][j])
                dist[j] = g[p][j];
    }
    if (cnt != n) cout << "impossible";
    else cout << sum;
}
