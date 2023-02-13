#include <iostream>

using namespace std;

const int N = 100010;
int n, a[N], t[N];

void sort(int l, int r) {
    if (l == r) return;

    int m = (l + r) / 2;
    sort(l, m);
    sort(m + 1, r);

    int p = l, q = m + 1, k = 0;
    while (p <= m && q <= r) t[k++] = a[p] < a[q] ? a[p++] : a[q++];
    while (p <= m) t[k++] = a[p++];
    while (q <= r) t[k++] = a[q++];
    while (k) a[r--] = t[--k];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(1, n);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
