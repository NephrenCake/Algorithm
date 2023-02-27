#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N], ans, ne[N * 30][2], idx = 1;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int ch = x >> i & 1;  // x在高i位是0/1
        if (ne[p][ch] == 0) ne[p][ch] = idx++;
        p = ne[p][ch];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int ch = x >> i & 1;
        if (ne[p][!ch] != 0) p = ne[p][!ch], res += 1 << i;
        else p = ne[p][ch];
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], insert(a[i]);
    for (int i = 1; i <= n; i++) ans = max(ans, query(a[i]));
    cout << ans;
}
