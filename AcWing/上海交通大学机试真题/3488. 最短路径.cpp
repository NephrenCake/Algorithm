#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 110, MOD = 100000;
int n, m, p[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int dist[N], used[N];
typedef pair<int, int> PII;
vector<PII> v[N];

void dijkstra(int x) {
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (k == -1 || dist[k] > dist[j]))
                k = j;
        used[k] = 1;
        for (auto [ne, ds]: v[k])
            if (!used[ne])
                dist[ne] = (dist[k] + ds) % MOD;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0, a, b, t = 1; i < m; i++) {
        cin >> a >> b;
        if (i) t = (t * 2) % MOD;
        if (find(a) == find(b)) continue;
        p[find(a)] = find(b);
        v[a].push_back({b, t});
        v[b].push_back({a, t});
    }

    dijkstra(0);
    for (int i = 1; i < n; i++)
        if (dist[i] != 0x3f3f3f3f) cout << dist[i] << endl;
        else cout << -1 << endl;
}
