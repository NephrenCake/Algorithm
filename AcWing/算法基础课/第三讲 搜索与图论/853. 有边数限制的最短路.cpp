#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
int n, m, k, x[M], y[M], z[M], dist[N], backup[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> x[i] >> y[i] >> z[i];

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
            dist[y[j]] = min(dist[y[j]], backup[x[j]] + z[j]);
    }
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
}
