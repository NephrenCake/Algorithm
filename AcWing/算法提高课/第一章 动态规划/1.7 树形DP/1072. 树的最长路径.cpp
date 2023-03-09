#include <iostream>
#include <vector>

using namespace std;

const int N = 10010;
int n, ans;
typedef pair<int, int> PII;
#define p first
#define d second
vector<PII> v[N];

int dfs(int cur, int fa) {
    int d1 = 0, d2 = 0;
    for (auto ne: v[cur])
        if (ne.p != fa) {
            int d = dfs(ne.p, cur) + ne.d;
            if (d >= d1) d2 = d1, d1 = d;
            else if (d > d2) d2 = d;
        }
    ans = max(ans, d1 + d2);
    return d1;
}

int main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(1, -1);
    cout << ans;
}
