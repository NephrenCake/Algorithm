#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1080/

/**
 * todo ÔÙ×öÊ÷ÐÎdp
 */

const int N = 200010, M = N * 2;

int n, maxd;
int h[N], e[M], ne[M], idx;
int d1[N], d2[N], p1[N], up[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs_d(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != fa) {
            dfs_d(j, u);
            int d = d1[j] + 1;
            if (d > d1[u])
                d2[u] = d1[u], d1[u] = d, p1[u] = j;
            else if (d > d2[u])
                d2[u] = d;
        }
    }

    maxd = max(maxd, d1[u] + d2[u]);
}

void dfs_u(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != fa) {
            up[j] = up[u] + 1;
            if (p1[u] == j)
                up[j] = max(up[j], d2[u] + 1);
            else
                up[j] = max(up[j], d1[u] + 1);
            dfs_u(j, u);
        }
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs_d(0, -1);
    dfs_u(0, -1);

    for (int i = 0; i < n; ++i) {
        int d[3] = {d1[i], d2[i], up[i]};
        sort(d, d + 3);
        if (d[1] + d[2] == maxd)
            printf("%d\n", i);
    }
}