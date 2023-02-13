#include <iostream>

using namespace std;

const int N = 1000010;
int n, m, p[N], q[N], a, b, c, d;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= m; i++) cin >> q[i];
    cin >> a >> b >> c >> d;

    int idx = (d - c + b - a + 2) / 2 + (d - c + b - a + 2) % 2;
    if (idx <= b - a + 1) cout << p[a + idx - 1];
    else cout << q[idx - (b - a + 1) + c - 1];
}
