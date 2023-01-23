#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int n, m, v, w, s, f[N], g[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);  // f¸´ÖÆµ½g
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= s && j - k * v >= 0; k++)
                f[j] = max(f[j],  g[j - k * v] + k * w);
        }
    }
    cout << f[m];
}
