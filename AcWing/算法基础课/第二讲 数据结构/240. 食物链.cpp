#include <iostream>

using namespace std;

const int N = 50010;
int p[N], d[N], ans;

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] = (d[x] + d[p[x]]) % 3;
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, k, a, b, c;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    while (k-- && cin >> c >> a >> b) {
        c = c == 2 ? 1 : 0;
        int pa = find(a), pb = find(b);
        if (a > n || b > n || c == 1 && a == b) {
            ans++;
            continue;
        }
        if (pa == pb) {
            if (((d[a] - d[b]) % 3 + 3) % 3 != c)
                ans++;
        } else {
            p[pa] = pb;
            d[pa] = d[b] - d[a] + c;  // (d[a] + ?) % 3 == (d[b] + rel) % 3
        }
    }
    cout << ans;
}
