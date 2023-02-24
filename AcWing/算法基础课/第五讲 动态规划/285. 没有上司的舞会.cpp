#include <iostream>
#include <vector>

using namespace std;

const int N = 6010;
int n, happy[N], fa[N], f[N][2];
vector<int> v[N];

void dfs(int idx) {
    f[idx][1] = happy[idx];
    for (auto ne: v[idx]) {
        dfs(ne);
        f[idx][0] += max(f[ne][0], f[ne][1]);
        f[idx][1] += f[ne][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> happy[i];
    for (int i = 1, a, b; i <= n - 1; i++) {
        cin >> a >> b;  // b->a
        v[b].push_back(a);
        fa[a] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (!fa[i]) {
            root = i;
            break;
        }
    dfs(root);
    cout << max(f[root][0], f[root][1]);
}
