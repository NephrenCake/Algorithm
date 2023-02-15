#include <iostream>

using namespace std;

const int N = 50010;
int ans, p[N], d[N];

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] = (d[x] + d[p[x]]) % 3;
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    while (k--) {
        int t, a, b;
        cin >> t >> a >> b;
        int ra = find(a), rb = find(b);

        if (a > n || b > n || t == 2 && a == b)
            ans++;
        else {
            int rel = t == 2 ? 1 : 0;
            if (ra == rb && ((d[a] - d[b]) % 3 + 3) % 3 != rel) {
                ans++;
            } else {
                p[ra] = rb;
                d[ra] = d[b] - d[a] + rel;  // (d[a] + ?) % 3 == (d[b] + rel) % 3
            }
        }
    }
    cout << ans;
}
