#include <iostream>
#include <queue>

using namespace std;

const int N = 100010, M = 2 * N;
int n, m, u[M], v[M], p[N], ans, cnt;
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<>> h;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1, w; i <= m; i++) {
        cin >> u[i] >> v[i] >> w;
        h.push({w, i});
    }

    for (int i = 1; i <= n; i++) p[i] = i;
    while (!h.empty()) {
        int w = h.top().first, i = h.top().second;
        int a = find(u[i]), b = find(v[i]);
        h.pop();
        if (a == b) continue;
        p[a] = b;
        ans += w;
        cnt++;
    }
    if (cnt != n - 1) {
        cout << "impossible";
        return 0;
    }
    cout << ans;
}
