#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, dist[N], used[N];
typedef pair<int, int> PII;
#define d first
#define p second
vector<PII> v[N];
unordered_set<int> wait[N];
priority_queue<PII, vector<PII>, greater<PII>> h;

int next(int x,int t) {
    int cnt = 0;
    while (wait[x].count (t)) t++,cnt++;
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    for (int i = 1, s, t; i <= n; i++) {
        cin >> s;
        while (s--) cin >> t, wait[i].insert(t);
    }

    // 迪杰斯特拉
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    h.push({0, 1});
    while (h.size()) {
        int p = h.top().second, d = dist[p];
        h.pop();
        if (used[p]) continue;
        used[p] = 1;
        if (p == n) break;
        while (wait[p].count(d)) d++;  // 延迟出发
        for (auto ne: v[p])
            // if (!used[ne.p] && dist[ne.p] > d + ne.d) {
            if (dist[ne.p] > d + ne.d) {
                dist[ne.p] = d + ne.d;
                h.push({dist[ne.p], ne.p});
            }
    }
    if (dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];
}
