#include <iostream>

using namespace std;

const int N = 100010;
int n, m, a[N], b[N], l, r, c;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    while (m--) {
        cin >> l >> r >> c;
        b[l] += c, b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = b[i] + b[i - 1];
        cout << b[i] << " ";
    }
}
