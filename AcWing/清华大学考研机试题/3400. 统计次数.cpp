#include <iostream>

using namespace std;

typedef unsigned long long ULL;
ULL power10(int n) {
    ULL res = 1;
    while (n--) res *= 10;
    return res;
}

ULL cnt(int a, int x) {
    ULL res = 0, len = to_string(a).size();
    for (int i = 1; i <= len; i++) {
        ULL r = power10(i - 1), l = a / power10(i), m = a / r % 10;
        if (x != 0) res += r * l;
        else res += r * (l - 1);
        if (m == x) res += a % r + 1;
        else if (m > x) res += r;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << cnt(n, k);
}
