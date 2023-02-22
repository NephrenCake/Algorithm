#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int n, m, x[M], y[M], p[N], ans, cnt;
typedef pair<int, int> PII;
#define d first
#define ptr second
priority_queue<PII, vector<PII>, greater<PII>> h;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1, c; i <= m; i++) cin >> x[i] >> y[i] >> c, h.push({c, i});
    for (int i = 1; i <= n; i++) p[i] = i;

    while (!h.empty()) {
        PII cur = h.top();
        h.pop();
        if (find(x[cur.ptr]) == find(y[cur.ptr])) continue;
        p[find(x[cur.ptr])] = find(y[cur.ptr]);
        ans += cur.d;
        cnt++;
    }
    if (cnt != n - 1) cout << "impossible";
    else cout << ans;
}
