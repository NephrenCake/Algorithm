#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 2010;
int n, m, dist[N], used[N], cnt[N];
typedef pair<int, int> PII;
#define p first
#define d second
vector<PII> v[N];
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; i++) cin >> a >> b >> c, v[a].push_back({b, c});

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
                cnt[ne.p] = cnt[cur] + 1;
                if (cnt[ne.p] > n) {
                    cout << "Yes";
                    return 0;
                }
                if (!used[ne.p])
                    q.push(ne.p), used[ne.p] = 1;
            }
    }
    cout << "No";
}
