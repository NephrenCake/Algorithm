#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010;
int n, a[N], t[N];

LL sort(int l, int r) {
    if (l == r) return 0;
    int m = (l + r) >> 1;
    LL res = sort(l, m) + sort(m + 1, r);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            t[k++] = a[i++];
        else {
            res += m - i + 1;
            t[k++] = a[j++];
        }
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    while (k) a[--j] = t[--k];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << sort(1, n);
}
