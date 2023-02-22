#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, dist[N], used[N];  // used表示在队列中
typedef pair<int, int> PII;
#define p first
#define d second
vector<PII> v[N];
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; i++)
        cin >> a >> b >> c, v[a].push_back({b, c});

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) q.push(i), used[i] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        used[cur] = 0;
        for (auto ne: v[cur])
            if (dist[ne.p] > dist[cur] + ne.d) {
                dist[ne.p] = dist[cur] + ne.d;
                if (!used[ne.p])
                    q.push(ne.p), used[ne.p] = 1;
            }
    }
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
}
