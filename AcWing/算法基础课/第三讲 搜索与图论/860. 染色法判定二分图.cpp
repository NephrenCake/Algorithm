#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, m, st[N];
vector<int> ve[N];
bool flag = true;

void dfs(int cur) {
    if (!flag) return;
    for (int i: ve[cur]) {
        if (st[i] == 3 - st[cur]) continue;
        if (st[i] == st[cur]) flag = false;
        st[i] = 3 - st[cur];
        // printf("%d %d\n", i, st[i]);
        dfs(i);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        // if (u == v) continue;  // 自环也不能算作二分图
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)  // 可能非连通
        if (!st[i]) {
            st[i] = 1;
            dfs(i);
        }
    if (flag) cout << "Yes";
    else cout << "No";
}
