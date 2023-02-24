#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1, t = a;
    while (b) {
        if (b & 1) res = res * t % p;
        t = t * t % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, a, p;
    cin >> n;
    while (n-- && cin >> a >> p)
        if (a % p == 0) cout << "impossible" << endl;
        else cout << qmi(a, p - 2, p) << endl;
}
