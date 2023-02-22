#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 150010;
int n, m, dist[N], used[N];
typedef pair<int, int> PII;
#define d first
#define p second
vector<PII> v[N];
priority_queue<PII, vector<PII>, greater<>> h;  // 距离，点

int main() {
    cin >> n >> m;
    int a, b, c;
    while (cin >> a >> b >> c) v[a].push_back({c, b});  // 距离，点

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    h.push({0, 1});
    while (!h.empty()) {
        // 找点
        PII cur = h.top();
        h.pop();
        if (used[cur.p]) continue;
        // 更新
        used[cur.p] = 1;
        // 使用
        for (PII ne: v[cur.p])
            if (!used[ne.p] && dist[ne.p] > cur.d + ne.d)
                dist[ne.p] = cur.d + ne.d, h.push({cur.d + ne.d, ne.p});
    }
    if (dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];
}
