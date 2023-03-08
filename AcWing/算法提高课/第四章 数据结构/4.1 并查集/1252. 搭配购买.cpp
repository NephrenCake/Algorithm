#include <iostream>

using namespace std;

const int N = 10010;
int n, m, w, p[N], c[N], d[N], u, v;
int f[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++)
        p[i] = i, cin >> c[i] >> d[i];
    while (m-- && cin >> u >> v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            c[pv] += c[pu];
            d[pv] += d[pu];
            p[pu] = pv;
        }
    }
    for (int i = 1; i <= n; i++)
        if (i == find(i))
            for (int j = w; j >= c[i]; j--)
                f[j] = max(f[j], f[j - c[i]] + d[i]);
    cout << f[w];
}
