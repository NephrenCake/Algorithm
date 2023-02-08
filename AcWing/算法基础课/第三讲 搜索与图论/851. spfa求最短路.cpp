#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, dist[N], used[N];
typedef pair<int, int> PII;
#define d first
#define p second
vector<PII> v[N];
queue<int> q;

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    used[1] = 1;
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        used[cur] = 0;
        for (auto i: v[cur]) {
            if (dist[i.p] > dist[cur] + i.d) {
                dist[i.p] = dist[cur] + i.d;
                if (used[i.p]) continue;
                q.push(i.p);
                used[i.p] = 0;
            }
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
}
