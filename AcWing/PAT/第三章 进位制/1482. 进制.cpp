#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1484/

/**
 * 进制运算
 * 二分查找
 */

typedef long long LL;

LL val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else return c - 'a' + 10;
}

LL get_num(string &s, LL r) {
    long long res = 0;
    for (char &c: s) {
        if ((double)res * r + val(c) > 1e16) return 1e18;
        res = res * r + val(c);
    }
    return res;
}

int main() {
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;

    LL target;
    string source;
    if (tag == 1) target = get_num(N1, radix), source = N2;
    else target = get_num(N2, radix), source = N1;

    LL ans;
    LL l = 1, r = target + 1, m;
    for (auto &c: source) l = max(l, val(c) + 1);
    while (l < r) {
        m = (l + r) >> 1;
        if (target <= get_num(source, m)) r = m;
        else l = m + 1;
    }
    ans = get_num(source, r);
    if (ans == target) cout << r;
    else cout << "Impossible";
}
