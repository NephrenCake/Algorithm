#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, m, c[N], ans = 1;
vector<int> v[N];

void dfs(int idx, int last) {
    if (ans == 0) return;
    c[idx] = last == 1 ? 2 : 1;
    for (auto ne: v[idx])
        if (c[ne] == 0) dfs(ne, c[idx]);
        else if (c[ne] == c[idx]) ans = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++)  // 自环不能算作二分图
        cin >> a >> b, v[b].push_back(a), v[a].push_back(b);
    for (int i = 1; i <= n; i++)
        if (!c[i])
            dfs(i, 1);
    if (ans) cout << "Yes";
    else cout << "No";
}
