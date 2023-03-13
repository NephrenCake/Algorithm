#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
#define p first
#define d second
const int N = 10010;
int n, d1[N], d2[N], up[N], s1[N], s2[N], ans = 0x3f3f3f3f;
vector<PII> v[N];

int dfs1(int cur, int fa) {
    for (auto ne: v[cur])
        if (ne.p != fa) {
            int d = dfs1(ne.p, cur) + ne.d;
            if (d >= d1[cur])
                d2[cur] = d1[cur], d1[cur] = d, s2[cur] = s1[cur], s1[cur] = ne.p;
            else if (d > d2[cur])
                d2[cur] = d, s2[cur] = ne.p;
        }
    return d1[cur];
}

int dfs2(int cur, int fa) {
    for (auto ne: v[cur])
        if (ne.p != fa) {
            if (s1[cur] == ne.p) up[ne.p] = ne.d + max(up[cur], d2[cur]);  // 用向下的次大路径来更新最大路径孩子的向上最大路径
            else up[ne.p] = ne.d + max(up[cur], d1[cur]);  // 用向下的最大路径来更新每个孩子的向上最大路径
            dfs2(ne.p, cur);
        }
}

int main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs1(1, -1);
    dfs2(1, -1);

    for (int i = 1; i <= n; i++) ans = min(ans, max(d1[i], up[i]));
    cout << ans;
}
