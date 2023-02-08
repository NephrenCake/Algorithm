#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
int n, m, k, a[M], b[M], w[M], dist[N], backup[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> w[i];

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
            dist[b[j]] = min(dist[b[j]], backup[a[j]] + w[j]);
    }
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
}
