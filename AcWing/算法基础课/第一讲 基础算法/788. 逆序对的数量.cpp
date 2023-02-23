#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010;
int n, a[N], t[N];

LL sort(int l, int r) {
    if (l == r) return 0;
    int m = (l + r) / 2, p = l, q = m + 1, k = 0;
    LL res = sort(l, m) + sort(m + 1, r);
    while (p <= m && q <= r) {
        if (a[p] <= a[q]) {
            t[k++] = a[p++];
        } else {
            res += m - p + 1;
            t[k++] = a[q++];
        }
    }
    while (p <= m) t[k++] = a[p++];
    while (q <= m) t[k++] = a[q++];
    while (q > l) a[--q] = t[--k];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << sort(1, n);
}
