#include <iostream>
#include <vector>

using namespace std;

const int N = 6010;
int n, h[N], f[N][2], has_fa[N];
vector<int> v[N];

void dfs(int cur) {
    f[cur][1] = h[cur];
    for (auto ch: v[cur]) {
        dfs(ch);
        f[cur][0] += max(f[ch][0], f[ch][1]);
        f[cur][1] += f[ch][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1, l, k; i <= n - 1; i++) cin >> l >> k, v[k].push_back(l), has_fa[l] = 1;

    int root;
    for (int i = 1; i <= n; i++)
        if (!has_fa[i]) {
            root = i;
            break;
        }
    dfs(root);
    cout << max(f[root][0], f[root][1]);
}
