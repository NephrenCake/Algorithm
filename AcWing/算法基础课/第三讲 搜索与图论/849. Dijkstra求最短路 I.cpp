#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int n, m, g[N][N], dist[N], used[N];

int main() {
    cin >> n >> m;
    int a, b, c;
    memset(g, 0x3f, sizeof g);
    while (cin >> a >> b >> c) g[a][b] = min(g[a][b], c);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!used[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        used[t] = 1;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];
}
