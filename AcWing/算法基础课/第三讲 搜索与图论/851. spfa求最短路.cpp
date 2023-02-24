#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, z, used[N], dist[N];  // used表示在队列中
typedef pair<int, int> PII;
#define d first
#define p second
vector<PII> v[N];
queue<int> q;

int main() {
    cin >> n >> m;
    while (m-- && cin >> x >> y >> z) v[x].push_back({z, y});

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) q.push(i), used[i] = 1;
    while (!q.empty()) {
        // 找点
        int cur = q.front();
        q.pop();
        // 更新
        used[cur] = 0;
        // 使用
        for (auto ne: v[cur])
            if (dist[ne.p] > dist[cur] + ne.d) {
                dist[ne.p] = dist[cur] + ne.d;
                if (!used[ne.p]) q.push(ne.p);
            }
    }
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
}
