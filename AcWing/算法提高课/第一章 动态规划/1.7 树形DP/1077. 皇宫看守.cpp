#include <iostream>
#include <vector>

using namespace std;

const int N = 1510;
int w[N], f[N][3];
vector<int> v[N];

void dfs(int idx) {
    // 0 不放且被父节点观察  1 不放且被子节点观察  2 放
    f[idx][0] = 0;
    f[idx][1] = 1e9;
    f[idx][2] = w[idx];
    for (int ne: v[idx]) {
        dfs(ne);
        f[idx][0] += min(f[ne][1], f[ne][2]);
        f[idx][2] += min(min(f[ne][0], f[ne][1]), f[ne][2]);
    }
    for (int ne: v[idx]) {
        f[idx][1] = min(f[idx][1], f[idx][0] + f[ne][2] - min(f[ne][1], f[ne][2]));
    }
}

int main() {
    int n, idx, k, m, ne, fa[N];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> idx >> k >> m;
        w[idx] = k;
        while (m-- && cin >> ne) {
            v[idx].push_back(ne);
            fa[ne] = 1;
        }
    }
    int p = -1;
    for (int i = 1; i <= n; i++)
        if (!fa[i]) {
            p = i;
            break;
        }
    dfs(p);
    cout << min(f[p][1], f[p][2]);
}
