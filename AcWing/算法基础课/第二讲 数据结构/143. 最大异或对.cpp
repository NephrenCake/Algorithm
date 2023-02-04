#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N], ans, son[31 * N][2], idx;

void insert(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = num >> i & 1;
        if (son[p][u] == 0) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int num) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = num >> i & 1;
        if (son[p][!u] != 0) {
            res = (res << 1) + 1;
            p = son[p][!u];
        } else {
            res = (res << 1);
            p = son[p][u];
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], insert(a[i]);

    for (int i = 0; i < n; i++)
        ans = max(ans, query(a[i]));
    cout << ans;
}
