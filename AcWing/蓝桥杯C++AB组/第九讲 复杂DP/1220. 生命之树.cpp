#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/description/1222/

/**
 * todo 再做
 */

typedef long long LL;
const int N = 1e5 + 10;

int n;
LL f[N];
int w[N];
int h[N], e[N * 2], ne[N * 2], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 第二个参数是记录父节点，防止向回走
void dfs(int u, int fa) {
    f[u] = w[u];

    for (int p = h[u]; p != -1; p = ne[p]) {
        int j = e[p];
        if (j != fa) {
            dfs(j, u);
            f[u] += max(0ll, f[j]);
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);//无向图
    }

    //树形DP
    dfs(1, -1);

    LL res = -1e10;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);

    cout << res << endl;
    return 0;
}
