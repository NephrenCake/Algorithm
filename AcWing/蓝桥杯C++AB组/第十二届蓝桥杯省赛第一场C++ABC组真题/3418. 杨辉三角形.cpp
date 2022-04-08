#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3421/

typedef long long LL;

int n;

LL C(int a, int b) {
    // C(a, b) = a!/b!(a-b)!
    LL res = 1;
    for (int i = a, j = 1; j <= b; i--, j++) {
        res = res * i / j;
        if (res > n) return res;  // 大于n已无意义，且防止爆LL
    }
    return res;
}

bool check(int k) {
    int l = 2 * k, r = max(n, l);
    while (l < r) {
        int m = (l + r) >> 1;
        if (n <= C(m, k)) r = m;  // 找第一个大于等于tar的数
        else l = m + 1;
    }
    if (C(r, k) != n) return false;

    cout << 1ll * (r + 1) * r / 2 + k + 1 << endl;
    return true;
}

int main() {
    cin >> n;
    // 从下往上枚举16个斜行，不重不漏，必有解
    // k代表第几斜行，也代表该数值在行中的位数（0开始计数）
    for (int k = 16;; k--)
        if (check(k)) break;
}
