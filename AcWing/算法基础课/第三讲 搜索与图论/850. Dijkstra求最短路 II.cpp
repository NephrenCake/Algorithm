#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e5 + 10;
int n, m, x, y, z, dist[N], used[N];  // used表示已访问
typedef pair<int, int> PII;
#define d first
#define p second
vector<PII> v[N];
priority_queue<PII, vector<PII>, greater<PII>> h;

int main() {
    cin >> n >> m;
    while (m-- && cin >> x >> y >> z) v[x].push_back({z, y});  // x->z(y)

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    h.push({0, 1});
    while (!h.empty()) {
        // 找点
        auto cur = h.top();
        h.pop();
        if (used[cur.p]) continue;
        // 更新
        used[cur.p] = 1;
        // 使用
        for (auto ne: v[cur.p])
            if (!used[ne.p] && dist[ne.p] > dist[cur.p] + ne.d) {
                dist[ne.p] = dist[cur.p] + ne.d;
                h.push({dist[ne.p], ne.p});
            }
    }
    if (dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];
}
