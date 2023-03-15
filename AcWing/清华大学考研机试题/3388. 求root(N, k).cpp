#include <iostream>

using namespace std;

typedef unsigned long long ULL;
int x, y, k;

ULL qmi(int a, int b, int q) {
    ULL res = 1, t = a;
    while (b) {
        if (b & 1) res = (res * t) % q;
        t = (t * t) % q;
        b >>= 1;
    }
    return res;
}

int main() {
    while (cin >> x >> y >> k) {
        ULL res = qmi(x, y, k - 1);
        if (res) cout << res << endl;
        else cout << k - 1 << endl;
    }
}
