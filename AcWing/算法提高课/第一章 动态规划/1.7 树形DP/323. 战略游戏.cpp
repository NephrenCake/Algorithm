#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1510;
int n, fa[N], f[N][2];
vector<int> v[N];

void dfs(int idx) {
    f[idx][1] = 1;
    f[idx][0] = 0;
    for (int ne: v[idx]) {
        dfs(ne);
        f[idx][1] += min(f[ne][1], f[ne][0]);
        f[idx][0] += f[ne][1];
    }
}

int main() {
    while (cin >> n) {
        memset(fa, 0, sizeof fa);
        for (int i = 0, cur, cnt, ne; i < n; i++) {
            scanf("%d:(%d)", &cur, &cnt);
            v[cur].clear();
            for (int i = 1; i <= cnt; i++) {
                cin >> ne;
                v[cur].push_back(ne);
                fa[ne] = 1;
            }
        }
        int p = -1;
        for (int i = 0; i < n; i++)
            if (!fa[i]) {
                p = i;
                break;
            }
        dfs(p);
        cout << min(f[p][1], f[p][0]) << endl;
    }
}
