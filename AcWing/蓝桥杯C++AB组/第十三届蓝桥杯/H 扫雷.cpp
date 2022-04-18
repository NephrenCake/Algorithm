#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 10000000 + 10, MOD = 1000000007;

LL n, m;
vector<vector<int>> dls;
vector<vector<int>> hjs;
LL ans;
int x, y, r;

int bomb(int x1, int y1, int x2, int y2, int r_) {
    int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return d <= r_ * r_;
}

void dfs(int now) {
    dls[now][3] = 1;
    for (int j = 0; j < n; j++)
        if (bomb(dls[now][0], dls[now][1], dls[j][0], dls[j][1], dls[now][2]) && dls[j][3] == 0)
            dfs(j);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> r;
        dls.push_back({x, y, r, 0});
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> r;
        hjs.push_back({x, y, r});
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (bomb(hjs[i][0], hjs[i][1], dls[j][0], dls[j][1], hjs[i][2]))
                dfs(j);

    for (int j = 0; j < n; j++)
        if (dls[j][3] == 1)
            ans++;
    cout << ans << endl;
    return 0;
}
