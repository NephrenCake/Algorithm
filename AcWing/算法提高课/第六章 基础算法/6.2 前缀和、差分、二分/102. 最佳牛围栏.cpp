#include <iostream>

using namespace std;

const int N = 100010;
int n, f;
double a[N], l, r, m, s[N], minv;

bool check(double tar) {
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - tar;

    minv = 1e9;
    for (int i = 0, j = f; j <= n; i++, j++) {
        minv = min(minv, s[i]);
        if (s[j] - minv > 0) return true;
    }
    return false;
}

int main() {
    cin >> n >> f;
    for (int i = 1; i <= n; i++) cin >> a[i], r = max(r, a[i]);

    while (r - l > 1e-8) {
        m = (l + r) / 2;
        if (check(m)) l = m;  // 猜的平均值低于真实值
        else r = m;
    }
    cout << int (r * 1000);
}
