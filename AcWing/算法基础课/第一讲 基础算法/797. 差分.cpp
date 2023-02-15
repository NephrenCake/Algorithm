#include <iostream>

using namespace std;

const int N = 100010;
int n, m, a[N];

void add(int l, int r, int c) {
    a[l] += c, a[r + 1] -= c;
}

int main() {
    cin >> n >> m;
    for (int i = 1, t; i <= n; i++)
        cin >> t, add(i, i, t);
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        add(l, r, c);
    }
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1], cout << a[i] << " ";
}
