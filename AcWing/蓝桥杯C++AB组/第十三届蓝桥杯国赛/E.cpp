#include <bits/stdc++.h>

using namespace std;

struct road {
    int u, v, c;
};

const int N = 1010, M = 10010;
int n, m, ans = 1e9;  // N 表示A 国的城市数量，M 表示未关闭的路线数量

int c[N];  // 到达编号为i 的城市后需要隔离的时间
vector<road> rs[N];  // 出边数组

bool used[N];

void dfs(int cur_city, int cur_cost) {
    if (cur_city == n) {
        ans = min(ans, cur_cost);
        // cout << ans << endl;
        return;
    }

    cur_cost += c[cur_city];
    // cout << cur_city << " " << cur_cost << " " << c[cur_city] << endl;
    for (auto item: rs[cur_city])
        if (!used[item.v]) {
            used[item.v] = true;
            dfs(item.v, cur_cost + item.c);
            used[item.v] = false;
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++) {
        int u_, v_, c_;
        cin >> u_ >> v_ >> c_;
        rs[u_].push_back({u_, v_, c_});
    }

    used[1] = true;
    for (auto item: rs[1])
        if (!used[item.v]) {
            used[item.v] = true;
            dfs(item.v, item.c);
            used[item.v] = false;
        }
    cout << ans;
    return 0;
}
/*
4 4
5 7 3 4
1 2 4
1 3 5
2 4 3
3 4 5

 */
