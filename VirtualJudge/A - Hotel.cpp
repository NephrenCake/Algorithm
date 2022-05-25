#include <bits/stdc++.h>

using namespace std;

// https://vjudge.net/contest/485551#problem/A

#define lowbit(x) x & (-x)
#define N 16010

int c[N], n, p;

void update(int x, int w) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += w;
}

int query(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return 0;
}

void init() {
    for (int i = 1; i <= n; ++i) {
        int w;
        cin >> w;
        update(i, w);
    }
}

int main() {
    cin >> n >> p;
    while (p--) {
        int t;
        cin >> t;
        if (t == 3)

    }
}
