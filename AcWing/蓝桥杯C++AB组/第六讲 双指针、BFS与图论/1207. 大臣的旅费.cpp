#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1209/

const int N = 1e5 + 10;

int n;
struct Edge {
    int id, w;
};
vector<Edge> h[N];
int dist[N];

void dfs(int u, int fa, int dis) {
    dist[u] = dis;
    for (auto node: h[u])
        if (node.id != fa)
            dfs(node.id, u, dis + node.w);
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        // 1 ≤ Pi, Qi ≤ n,
        // 1 ≤ Di ≤ 1000
        int p, q, d;
        cin >> p >> q >> d;
        h[p].push_back({q, d});
        h[q].push_back({p, d});
    }

    dfs(1, -1, 0);

    int u = 1;
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[u])
            u = i;

    dfs(u, -1, 0);
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[u])
            u = i;
    int s = dist[u];
    cout << s * 10 + s * (s + 1ll) / 2;  // 注意只需要 1 加上 ll，就可以转化成 long long，防止爆 int
}
