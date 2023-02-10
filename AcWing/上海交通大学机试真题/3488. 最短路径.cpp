#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 110, MOD = 100000;
int n, m, dist[N], used[N], p[N];
struct node {
    int ne, ds;
};
vector<node> v[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void dijkstra(int x) {
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (k == -1 || dist[k] > dist[j]))
                k = j;
        used[k] = 1;
        for (auto it : v[k]) {
            int ne = it.ne, ds = it.ds;
            if (!used[ne])
                dist[ne] = (dist[k] + ds) % MOD;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i;
    int a, b, d = 1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (i) d = d * 2 % MOD;
        if (find(a) == find(b)) continue;
        p[a] = b;
        v[a].push_back({b, d});  // a到的b节点，距离d
        v[b].push_back({a, d});  // b到的a节点，距离d
    }

    dijkstra(0);
    for (int i = 1; i < n; i++)
        if (dist[i] != 0x3f3f3f3f) cout << dist[i] << endl;
        else cout << -1 << endl;
}
