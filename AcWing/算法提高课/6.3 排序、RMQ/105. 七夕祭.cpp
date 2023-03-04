#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
LL n, m, k, row[maxn], col[maxn], s[maxn];

LL get(LL a[], LL x) {
    LL ans = 0;
    for (int i = 1; i <= x; ++i) ans += a[i];
    ans /= x;
    for (int i = 1; i <= x; ++i) a[i] -= ans;
    s[1] = 0;
    for (int i = 2; i <= x; ++i) s[i] = s[i - 1] + a[i];
    sort(s + 1, s + x + 1);
    LL mid = s[x / 2 + 1], sum = 0;
    for (int i = 1; i <= x; ++i) sum += abs(s[i] - mid);
    return sum;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1, x, y; i <= k; ++i)
        cin >> x >> y, row[x]++, col[y]++;
    if (k % n && k % m) printf("impossible");
    else if (k % n) printf("column %lld", get(col, m));
    else if (k % m) printf("row %lld", get(row, n));
    else printf("both %lld", get(row, n) + get(col, m));
}
